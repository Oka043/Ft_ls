/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:34:57 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:34:58 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static long long	count_blocks(t_file **child)
{
	long long	blocks;
	int			i;

	blocks = 0;
	i = 0;
	while (child[i])
		blocks += child[i++]->block_size;
	return (blocks);
}

void				print_long(int *max, int flags, char **stats)
{
	ft_printf("%s ", stats[0]);
	ft_printf("%*s ", VWF(0, 1));
	if (!LSF(LS_GROUP))
		ft_printf("%-*s  ", VWF(1, 2));
	if (!LSF(LS_OMIT_GROUP))
		ft_printf("%-*s  ", VWF(2, 3));
	if (LSF(LS_GROUP) && LSF(LS_OMIT_GROUP))
		write(1, "  ", 2);
	if (stats[0][0] == 'b' || stats[0][0] == 'c')
		ft_printf(" %*s, %*s ", VWF(4, 7), VWF(5, 8));
	else
		ft_printf("%*s ", VWF(3, 4));
	ft_printf("%s ", stats[5]);
	ft_printf("%s\n", stats[6]);
}

void				print_files(int flags, t_file *file)
{
	t_file	*child;
	int		i;

	if (!file->child)
	{
		(LSF(LS_L))
			? print_long(NULL, flags, file->stats)
			: ft_printf("%s\n", file->stats[6]);
		return ;
	}
	if (LSF(LS_L))
	{
		set_padding(file);
		if (file->child_count)
			ft_printf("total %lld\n", count_blocks(file->child));
	}
	i = 0;
	while ((child = file->child[i++]))
	{
		(LSF(LS_L))
			? print_long(file->maxlen, flags, child->stats)
			: ft_printf("%s\n", child->stats[6]);
	}
}

void				print_recursive(int flags, t_file *file)
{
	int	i;

	if (file->child_count && !LSF(LS_F))
		stack_sort(flags, file->child, file->child_count);
	print_files(flags, file);
	if (!LSF(LS_REC) || !file->child_count)
	{
		i = 0;
		while (i < file->child_count)
			free_file(&file->child[i++]);
		free_file(&file);
		return ;
	}
	while ((file = get_next_dir(flags, file)))
		;
}

t_file				*get_next_dir(int flags, t_file *file)
{
	t_file	*child;

	while (file->i < file->child_count && (child = file->child[file->i++]))
	{
		if (child->stats[0][0] != 'd'
			|| !ft_strcmp(child->name, ".")
			|| !ft_strcmp(child->name, "..")
			|| !ft_printf("\n%s:\n", child->path)
			|| !loading_child(flags, child))
		{
			free_file(&child);
			continue ;
		}
		if (file->child_count && !LSF(LS_F))
			stack_sort(flags, child->child, child->child_count);
		print_files(flags, child);
		return (child);
	}
	child = (file->parent) ? file->parent : NULL;
	free_file(&file);
	return (child);
}
