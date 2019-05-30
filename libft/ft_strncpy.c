/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:50:13 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:38:31 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	if (len == 0)
		return (dst);
	d = dst;
	s = src;
	if ((*d++ = *s++) == '\0')
		while (--len != 0)
			*d++ = '\0';
	while (len-- > 1)
		if ((*d++ = *s++) == '\0')
			while (len-- != 1)
				*d++ = '\0';
	return (dst);
}
