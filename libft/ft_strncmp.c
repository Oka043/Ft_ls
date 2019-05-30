/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:33:17 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/05 11:35:23 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int		ft_strncmp(const char *n1, const char *n2, size_t i)
{
	size_t			j;

	j = 0;
	if (i == 0)
		return (0);
	while (n1[j] == n2[j] && j < i - 1)
	{
		if (n1[j] == '\0')
			return (0);
		++j;
	}
	return ((unsigned char)n1[j] - (unsigned char)n2[j]);
}
