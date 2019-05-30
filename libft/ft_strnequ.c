/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:24:57 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:31:24 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			j;
	unsigned char	*n1;
	unsigned char	*n2;

	j = 0;
	n1 = (unsigned char *)s1;
	n2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	while ((n1[j] || n2[j]) && j < n)
	{
		if (n1[j] != n2[j])
			return (0);
		j++;
	}
	return (1);
}
