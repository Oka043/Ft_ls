/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:33:45 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:33:51 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/ft_printf.h"
#include "ft_ls.h"

int				get_max_width(int field, t_file **child)
{
	t_file	*ch;
	int		max;
	int		len;
	int		i;
	int		tmp;

	max = 0;
	i = 0;
	while ((ch = child[i++]))
	{
		len = 0;
		if (field == 4 && (ch->stats[0][0] == 'b' || ch->stats[0][0] == 'c'))
		{
			if ((len = ft_strlen(ch->stats[7])) > ch->parent->maxlen[4])
				ch->parent->maxlen[4] = len;
			if ((len = ft_strlen(ch->stats[8])) > ch->parent->maxlen[5])
				ch->parent->maxlen[5] = len;
			len = ch->parent->maxlen[4] + ch->parent->maxlen[5] + 3;
		}
		if ((tmp = ft_strlen(ch->stats[field])) > len)
			len = tmp;
		if (len > max)
			max = len;
	}
	return (max);
}

void			set_padding(t_file *file)
{
	file->maxlen[0] = get_max_width(1, file->child);
	file->maxlen[1] = get_max_width(2, file->child);
	file->maxlen[2] = get_max_width(3, file->child);
	file->maxlen[3] = get_max_width(4, file->child);
}

int				main(int argc, char **argv)
{
	t_file	**args;
	int		flags;
	int		idx;
	int		i;

	time(&g_time);
	flags = 0;
	idx = 0;
	g_app = ft_strrchr(argv[idx++], '/') + 1;
	if ((argc > 1 && !parse_flags(&idx, &flags, argv, argc))
		|| !(args = build_args(argc, idx, flags, argv)))
		return (1);
	i = 0;
	while (args[i])
	{
		if (!LSF(LS_D) && (argc - idx) > 1 && args[i]->child)
		{
			if (i > 0)
				write(1, "\n", 1);
			ft_printf("%s:\n", (args[i])->path);
		}
		print_recursive(flags, args[i++]);
	}
	free(args);
	return (0);
}
