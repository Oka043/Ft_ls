/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:35:24 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:35:25 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			get_type(mode_t st_mode)
{
	if (FMT(st_mode, S_IFREG))
		return ('-');
	else if (FMT(st_mode, S_IFDIR))
		return ('d');
	else if (FMT(st_mode, S_IFLNK))
		return ('l');
	else if (FMT(st_mode, S_IFCHR))
		return ('c');
	else if (FMT(st_mode, S_IFSOCK))
		return ('s');
	else if (FMT(st_mode, S_IFBLK))
		return ('b');
	else if (FMT(st_mode, S_IFIFO))
		return ('p');
	return ('-');
}

char			*get_time_str(int flags, t_file *file, t_stat *stats)
{
	struct timespec	spec;
	char			*ftime;

	if (LSF(LS_ATIME))
		spec = stats->st_atimespec;
	else if (LSF(LS_CTIME))
		spec = stats->st_ctimespec;
	else if (LSF(LS_BTIME))
		spec = stats->st_birthtimespec;
	else
		spec = stats->st_mtimespec;
	file->timestamp = spec;
	ftime = ctime(&spec.tv_sec);
	if (!(ftime = ft_strsub(ftime, 4, 20)))
		return (NULL);
	if (!LSF(LS_CT))
	{
		if (spec.tv_sec <= g_time && g_time - spec.tv_sec <= 15768000)
			*(ftime + 12) = '\0';
		else
			ft_memmove(ftime + 7, ftime + 15, 6);
	}
	return (ftime);
}

char			*get_permis(mode_t st_mode)
{
	char	*permis;

	if (!(permis = (char *)malloc(12)))
		return (NULL);
	permis[0] = get_type(st_mode);
	permis[1] = USR(S_IRUSR, 'r', '-');
	permis[2] = USR(S_IWUSR, 'w', '-');
	permis[3] = (st_mode & S_ISUID) ?
		USR(S_IXUSR, 's', 'S') : USR(S_IXUSR, 'x', '-');
	permis[4] = GRP(S_IRGRP, 'r', '-');
	permis[5] = GRP(S_IWGRP, 'w', '-');
	permis[6] = (st_mode & S_ISGID) ?
		GRP(S_IXGRP, 's', 'S') : GRP(S_IXGRP, 'x', '-');
	permis[7] = OTE(S_IROTH, 'r', '-');
	permis[8] = OTE(S_IWOTH, 'w', '-');
	permis[9] = (st_mode & S_ISVTX) ?
		OTE(S_IXOTH, 't', 'T') : OTE(S_IXOTH, 'x', '-');
	permis[11] = '\0';
	return (permis);
}

t_bool			is_simdir(t_file *file, int flags)
{
	t_stat	*stats;
	t_bool	simdir;

	if (!(stats = (t_stat *)ft_memalloc(sizeof(t_stat)))
		|| stat(file->path, stats) < 0)
	{
		free(stats);
		return (FALSE);
	}
	simdir = FMT(stats->st_mode, S_IFDIR);
	return (LSF(LS_L) ? FALSE : simdir);
}

t_bool			loading_stats(int flags, t_file *file, t_stat *stats)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(stats->st_uid);
	gr = getgrgid(stats->st_gid);
	if (!SET_STAT(0, get_permis(stats->st_mode))
		|| !SET_STAT(1, ft_itoa(stats->st_nlink))
		|| !SET_STAT(2, (pw) ? ft_strdup(pw->pw_name) : ft_itoa(stats->st_uid))
		|| !SET_STAT(3, (gr) ? ft_strdup(gr->gr_name) : ft_itoa(stats->st_gid))
		|| !SET_STAT(4, ft_itoa(stats->st_size))
		|| !SET_STAT(5, get_time_str(flags, file, stats))
		|| !SET_STAT(6, (FMT(stats->st_mode, S_IFLNK) && LSF(LS_L))
			? build_link(flags, file->name, file->path)
			: build_name(flags, file)))
		return (FALSE);
	if (file->stats[0][0] == 'b' || file->stats[0][0] == 'c')
	{
		if (!SET_STAT(7, ft_itoa(major(stats->st_rdev)))
			|| !SET_STAT(8, ft_itoa(minor(stats->st_rdev))))
			return (FALSE);
	}
	file->stats[0][10] = (listxattr(file->path, NULL, 0, XATTR_NOFOLLOW) > 0) ?
		'@' : ' ';
	return (TRUE);
}
