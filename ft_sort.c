/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:35:10 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:35:12 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp(const t_file *f1, const t_file *f2, int flags)
{
	const t_file	*tmp;

	if (LSF(LS_REV))
	{
		tmp = f1;
		f1 = f2;
		f2 = tmp;
	}
	if (LSF(LS_SIZE) && f1->byte_size != f2->byte_size)
		return (f1->byte_size < f2->byte_size);
	if (LSF(LS_MTIME) || (LSF(LS_MTIME) && (LSF(LS_ATIME) || LSF(LS_CTIME))))
	{
		if (f1->timestamp.tv_sec != f2->timestamp.tv_sec)
			return (f1->timestamp.tv_sec < f2->timestamp.tv_sec);
		if (f1->timestamp.tv_nsec != f2->timestamp.tv_nsec)
			return (f1->timestamp.tv_nsec < f2->timestamp.tv_nsec);
	}
	return (ft_strcmp(f1->name, f2->name));
}

void	max_stack(int flags, t_file **array, int node, int size)
{
	int		high;
	int		left;
	int		right;
	t_file	*tmp;

	while (TRUE)
	{
		high = node;
		left = (2 * node) + 1;
		right = (2 * node) + 2;
		if (left < size && cmp(array[left], array[high], flags) > 0)
			high = left;
		if (right < size && cmp(array[right], array[high], flags) > 0)
			high = right;
		if (high != node)
		{
			tmp = array[node];
			array[node] = array[high];
			array[high] = tmp;
			node = high;
		}
		else
			break ;
	}
}

int		dir_len(int flags, char *path)
{
	DIR			*dir;
	int			dlen;
	t_dirent	*dp;

	if (!(dir = ls_open(path)))
		return (-1);
	dlen = 0;
	while ((dp = ls_read(path, dir)))
	{
		if (skip_file(flags, dp->d_name))
			continue ;
		dlen++;
	}
	if (errno || ls_close(path, dir) < 0)
		return (-1);
	return (dlen);
}

void	stack_sort(int flags, t_file **child, int child_count)
{
	int		i;
	t_file	*tmp;

	i = (child_count / 2) - 1;
	while (i >= 0)
		max_stack(flags, child, i--, child_count);
	i = child_count - 1;
	while (i >= 0)
	{
		tmp = child[0];
		child[0] = child[i];
		child[i] = tmp;
		max_stack(flags, child, 0, i--);
	}
}
