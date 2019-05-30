/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:34:47 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:34:49 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const t_lsflag	g_lsflags[] = {
	{ 'A', LS_ALL, "", "" },
	{ 'F', LS_FTYPE, "", "p" },
	{ 'R', LS_REC, "", "" },
	{ 'S', LS_SIZE, "", "t" },
	{ 'T', LS_CT, "", "" },
	{ 'U', LS_BTIME, "", "Ucu" },
	{ 'a', LS_A, "", "" },
	{ 'c', LS_CTIME, "", "Uu" },
	{ 'd', LS_D, "", "" },
	{ 'f', LS_F, "a", "" },
	{ 'g', LS_GROUP, "l", "" },
	{ 'l', LS_L, "", "1" },
	{ 'o', LS_OMIT_GROUP, "l", "" },
	{ 'p', LS_P, "", "F" },
	{ 'r', LS_REV, "", "" },
	{ 't', LS_MTIME, "", "Ucu" },
	{ 'u', LS_ATIME, "", "Uc" },
	{ '1', LS_1, "", "l" },
};

const int		g_lsflag_count = sizeof(g_lsflags) / sizeof(t_lsflag);

static const t_lsflag	*get_flag(char c)
{
	int	i;

	i = 0;
	while (i < g_lsflag_count)
	{
		if (c == g_lsflags[i].c)
			return (&g_lsflags[i]);
		i++;
	}
	return (NULL);
}

void					set_flag(const t_lsflag *f, int *flags)
{
	int	i;
	int	c;

	i = 0;
	while (f->contrast[i])
	{
		c = get_flag(f->contrast[i++])->flag;
		if (*flags & c)
			*flags ^= c;
	}
	i = 0;
	while (f->obligatory[i])
		set_flag(get_flag(f->obligatory[i++]), flags);
	*flags |= f->flag;
}

t_bool					parse_flags(int *idx, int *flags, char **argv, int argc)
{
	char			*arg;
	const t_lsflag	*f;

	while (*idx < argc && (arg = argv[*idx]))
	{
		if (*arg != '-' || !*(arg + 1))
			break ;
		if (*(++arg) == '-')
		{
			if ((*idx > 2 && *(arg + 1) == '-' && !is_defis(arg))
				|| *(arg + 1))
				return (print_usage(*arg));
			else
				(*idx)++;
			break ;
		}
		while (*arg)
		{
			if (!(f = get_flag(*arg++)))
				return (print_usage(*(arg - 1)));
			set_flag(f, flags);
		}
		(*idx)++;
	}
	return (TRUE);
}

t_bool					is_defis(char *arg)
{
	DIR			*dir;
	t_dirent	*dp;
	int			n;
	int			i;
	t_bool		res;

	n = 0;
	while (arg[n] == '-')
		n++;
	if (!(dir = opendir(".")))
		return (FALSE);
	res = FALSE;
	while ((dp = readdir(dir)))
	{
		i = 0;
		while (i < n && dp->d_name[i] == '-')
			i++;
		if (i == n - 1 && !dp->d_name[i])
			res = TRUE;
	}
	if (closedir(dir) < 0)
		return (FALSE);
	return (res);
}

t_bool					print_usage(char c)
{
	int		i;

	write(2, g_app, ft_strlen(g_app));
	write(2, ": illegal option -- ", 20);
	write(2, &c, 1);
	write(2, "\nusage: ", 8);
	write(2, g_app, ft_strlen(g_app));
	write(2, " [-", 3);
	i = 0;
	while (i < g_lsflag_count)
		write(2, &g_lsflags[i++].c, 1);
	write(2, "] [file ...]\n", 13);
	return (FALSE);
}
