/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:42:26 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:42:29 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned char	*n1;
	unsigned char	*n2;
	size_t			i;
	size_t			j;

	i = ft_strlen(s1);
	j = 0;
	n1 = (unsigned char *)s1;
	n2 = (unsigned char *)s2;
	while (n2[j] && j < n)
	{
		n1[i + j] = n2[j];
		j++;
	}
	n1[i + j] = '\0';
	return ((char *)n1);
}
