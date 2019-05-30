/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:44:05 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:44:09 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strrchr(const char *str, int n)
{
	char	*res;
	char	b;

	if (!n)
		return ((char *)(str + ft_strlen(str)));
	res = NULL;
	b = (char)n;
	while (*str)
	{
		if (*str == b)
			res = (char *)str;
		str++;
	}
	return (res);
}
