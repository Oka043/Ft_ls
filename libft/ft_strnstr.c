/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:53:34 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:55:47 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t n)
{
	size_t			i;
	int				cnt;
	int				j;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)hay;
	n2 = (unsigned char *)ned;
	cnt = 0;
	i = 0;
	while (n2[cnt])
		cnt++;
	while ((n1[i] && i < n) || cnt == 0)
	{
		j = 0;
		while ((n1[i + j] == n2[j] && i + j < n) || cnt == 0)
		{
			if (j == cnt - 1 || cnt == 0)
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (0);
}
