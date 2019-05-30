/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:47:09 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:47:12 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		j;
	char	*dest;

	j = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (0);
	while (j < len)
	{
		dest[j] = f(j, s[j]);
		j++;
	}
	dest[len] = '\0';
	return (dest);
}
