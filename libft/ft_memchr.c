/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:57:53 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:57:56 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	chr;
	size_t			i;
	char			f;

	s = (unsigned char *)str;
	chr = (char)c;
	i = 0;
	f = 0;
	while (i != n)
	{
		if (s[i] == chr)
		{
			f++;
			return (s + i);
		}
		else
			i++;
	}
	return (0);
}
