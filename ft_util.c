/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:35:30 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:35:32 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*build_name(int flags, t_file *file)
{
	char	*dname;
	char	*tmp;
	t_bool	x;

	if (!LSF(LS_FTYPE) && !LSF(LS_P))
		return (ft_strdup(file->name));
	if (!(dname = (char *)malloc(ft_strlen(file->name) + 2)))
		return (NULL);
	tmp = ft_stpcpy(dname, file->name);
	if (STAT(0, 0) == 'd')
		*tmp++ = '/';
	if (!LSF(LS_P))
	{
		x = (STAT(0, 3) != '-' || STAT(0, 6) != '-' || STAT(0, 9) != '-');
		if (STAT(0, 0) == '-' && x)
			*tmp++ = '*';
		else if (STAT(0, 0) == 'l')
			*tmp++ = '@';
		else if (STAT(0, 0) == 's')
			*tmp++ = '=';
		else if (STAT(0, 0) == 'p')
			*tmp++ = '|';
	}
	*tmp = '\0';
	return (dname);
}

char		*build_link(int flags, char *link, char *path)
{
	char	target[256];
	char	*label;
	char	*tmp;
	int		len;

	if ((len = readlink(path, target, 255)) < 0)
		return (ls_error(path));
	target[len] = '\0';
	len = ft_strlen(link) + ft_strlen(target) + LSF(LS_FTYPE) + 5;
	if (!(label = (char *)malloc(len)))
		return (NULL);
	tmp = ft_stpcpy(label, link);
	if (LSF(LS_FTYPE))
		*tmp++ = '@';
	tmp = ft_stpcpy(tmp, " -> ");
	tmp = ft_stpcpy(tmp, target);
	return (label);
}

char		*build_path(char *parent, char *child)
{
	char	*path;
	char	*tmp;

	if (!(path = (char *)malloc(ft_strlen(parent) + ft_strlen(child) + 2)))
		return (NULL);
	tmp = ft_stpcpy(path, parent);
	if (*(tmp - 1) != '/')
		*tmp++ = '/';
	tmp = ft_stpcpy(tmp, child);
	return (path);
}
