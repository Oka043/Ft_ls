/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:07:34 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 15:41:04 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	char		*d;
	const char	*s;
	size_t		size;
	size_t		dest_len;

	d = dest;
	s = src;
	size = destsize;
	while (*d && size-- != 0)
		d++;
	dest_len = d - dest;
	size = destsize - dest_len;
	if (size == 0)
		return (dest_len + ft_strlen(src));
	while (*s)
	{
		if (size > 1)
		{
			size--;
			*d++ = *s;
		}
		s++;
	}
	*d = '\0';
	return (dest_len + (s - src));
}
