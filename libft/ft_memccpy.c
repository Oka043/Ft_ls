/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:56:30 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:56:35 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			i;
	unsigned char	f;

	str_dst = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	i = 0;
	f = (unsigned char)c;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == f)
		{
			str_dst[i] = str_src[i];
			return (dest + i + 1);
		}
		i++;
	}
	return (0);
}
