/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:45:21 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:55:14 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	str_src = (unsigned char *)str2;
	str_dst = (unsigned char *)str1;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (str_dst);
}
