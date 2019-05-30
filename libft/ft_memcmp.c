/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:13:38 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:59:18 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int		ft_memcmp(const void *m1, const void *m2, size_t n)
{
	size_t			i;
	size_t			res;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	res = 0;
	ch1 = (unsigned char *)m1;
	ch2 = (unsigned char *)m2;
	while (i < n)
	{
		if (ch1[i] < ch2[i] || ch1[i] > ch2[i])
		{
			res = ch1[i] - ch2[i];
			return (res);
		}
		else
			i++;
	}
	return (res);
}
