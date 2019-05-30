/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:57:27 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:57:32 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (s2 < s1)
	{
		i = 1;
		while (i <= len)
		{
			s1[len - i] = s2[len - i];
			i++;
		}
		return (s1);
	}
	else
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	return (s1);
}
