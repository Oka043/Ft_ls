/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:05:42 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:46:53 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*dest;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
