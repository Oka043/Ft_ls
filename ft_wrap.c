/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:35:38 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:35:39 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_close(char *path, DIR *dir)
{
	if (closedir(dir) < 0)
	{
		ls_error(path);
		return (-1);
	}
	return (0);
}

DIR				*ls_open(char *path)
{
	DIR	*dir;

	if (!(dir = opendir(path)))
		ls_error(path);
	return (dir);
}

struct dirent	*ls_read(char *path, DIR *dir)
{
	struct dirent	*dp;

	errno = 0;
	dp = readdir(dir);
	if (errno)
		ls_error(path);
	return (dp);
}
