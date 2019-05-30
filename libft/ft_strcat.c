/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:07:13 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:42:06 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	size_t			j;

	j = 0;
	i = (size_t)ft_strlen(s1);
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (s[j])
	{
		d[i + j] = s[j];
		j++;
	}
	d[i + j] = '\0';
	return ((char *)d);
}
