/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:34:32 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:34:34 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*build_file(char *name, int flags, char *path)
{
	t_file		*file;
	t_stat		*stats;

	stats = NULL;
	if (!(file = (t_file *)ft_memalloc(sizeof(t_file)))
		|| !(stats = (t_stat *)ft_memalloc(sizeof(t_stat)))
		|| !(file->name = ft_strdup(name))
		|| !(file->path = ft_strdup(path)))
		return (free_file(&file));
	if (lstat(path, stats) < 0 || !loading_stats(flags, file, stats))
	{
		ls_error(path);
		free(stats);
		return (free_file(&file));
	}
	file->block_size = stats->st_blocks;
	file->byte_size = stats->st_size;
	free(stats);
	return (file);
}

void		*free_file(t_file **file)
{
	int	i;

	free((*file)->name);
	free((*file)->path);
	i = 0;
	while ((*file)->stats[i])
		free((*file)->stats[i++]);
	free((*file)->child);
	free(*file);
	*file = NULL;
	return (NULL);
}

t_bool		skip_file(int flags, char *fname)
{
	if (LSF(LS_A))
		return (FALSE);
	else if (LSF(LS_ALL))
	{
		if (!ft_strcmp(fname, ".") || !ft_strcmp(fname, ".."))
			return (TRUE);
	}
	else if (*fname == '.')
		return (TRUE);
	return (FALSE);
}

t_file		*loading_parent(int flags, char *path)
{
	t_file	*file;
	t_stat	*stats;

	stats = NULL;
	if (!(file = (t_file *)ft_memalloc(sizeof(t_file)))
		|| !(file->name = ft_strdup(path))
		|| !(file->path = ft_strdup(path))
		|| !(stats = (t_stat *)ft_memalloc(sizeof(t_stat)))
		|| lstat(path, stats) < 0
		|| !loading_stats(flags, file, stats))
	{
		ls_error(path);
		free_file(&file);
	}
	if (!LSF(LS_D) && (FMT(stats->st_mode, S_IFDIR)
		|| (FMT(stats->st_mode, S_IFLNK) && is_simdir(file, flags))))
	{
		if (!loading_child(flags, file))
			free_file(&file);
	}
	free(stats);
	return (file);
}

t_bool		loading_child(int flags, t_file *file)
{
	DIR			*dir;
	t_dirent	*dp;
	char		*cpath;
	int			i;

	if ((file->child_count = dir_len(flags, file->path)) < 0
		|| !(file->child =
			(t_file **)ft_memalloc(sizeof(t_file *) * (file->child_count + 1)))
		|| !(dir = ls_open(file->path)))
		return (FALSE);
	i = 0;
	while ((dp = ls_read(file->path, dir)))
	{
		if (skip_file(flags, dp->d_name))
			continue ;
		if (!(cpath = build_path(file->path, dp->d_name))
			|| !(file->child[i] = build_file(dp->d_name, flags, cpath))
			|| !(file->child[i++]->parent = file))
		{
			free(cpath);
			return (FALSE);
		}
		free(cpath);
	}
	return (!errno && ls_close(file->path, dir) > -1);
}
