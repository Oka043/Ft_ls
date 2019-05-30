/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:33:44 by olaktion          #+#    #+#             */
/*   Updated: 2018/11/01 14:33:48 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*ls_error(char *path)
{
	char	*tmp;

	write(2, g_app, ft_strlen(g_app));
	write(2, ": ", 2);
	if (path)
	{
		if (!*path)
			path = "fts_open";
		if (errno != ENOENT && (tmp = ft_strrchr(path, '/')))
			path = tmp + 1;
		write(2, path, ft_strlen(path));
		write(2, ": ", 2);
	}
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (NULL);
}

t_bool		valid_args(int idx, char **argv)
{
	while (argv[idx])
	{
		if (!*argv[idx++])
		{
			errno = ENOENT;
			return (FALSE);
		}
	}
	return (TRUE);
}
