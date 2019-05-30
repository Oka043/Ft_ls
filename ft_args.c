/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:35:15 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:35:17 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			split_sort(int flags, t_file **args)
{
	int	folders;
	int	files;
	int	i;

	files = 0;
	folders = 0;
	i = 0;
	while (args[i])
	{
		if (args[i++]->child)
			folders++;
		else
			files++;
	}
	if (files)
		stack_sort(flags, args, files);
	if (folders)
		stack_sort(flags, &args[files], folders);
}

t_bool			sort_args(int argc, int idx, char **argv)
{
	char	*tmp;
	t_bool	change;
	int		i;

	if (!valid_args(idx, argv))
		return (FALSE);
	while (idx < argc)
	{
		change = FALSE;
		i = idx;
		while (++i < argc)
		{
			if (ft_strcmp(argv[i], argv[i - 1]) < 0)
			{
				tmp = argv[i];
				argv[i] = argv[i - 1];
				argv[i - 1] = tmp;
				change = TRUE;
			}
		}
		if (!change)
			break ;
	}
	return (TRUE);
}

void			sort_types(t_file **args)
{
	t_file	*tmp;
	t_bool	change;
	int		i;

	while (TRUE)
	{
		change = FALSE;
		i = 0;
		while (args[++i])
		{
			if (!args[i]->child && args[i - 1]->child)
			{
				tmp = args[i];
				args[i] = args[i - 1];
				args[i - 1] = tmp;
				change = TRUE;
			}
		}
		if (!change)
			break ;
	}
}

void			*free_args(t_file **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	return (NULL);
}

t_file			**build_args(int argc, int idx, int flags, char **argv)
{
	t_file	**array;
	int		len;
	int		i;

	if (!sort_args(argc, idx, argv))
		return (ls_error(""));
	len = (idx >= argc) ? 1 : (argc - idx);
	if (!(array = (t_file **)ft_memalloc(sizeof(t_file *) * (len + 1))))
		return (NULL);
	if (idx >= argc)
	{
		if (!(array[0] = loading_parent(flags, ".")))
			return (free_args(array));
		return (array);
	}
	i = 0;
	while (idx < argc)
	{
		if (!(array[i] = loading_parent(flags, argv[idx++])))
			continue ;
		i++;
	}
	sort_types(array);
	split_sort(flags, array);
	return (array);
}
