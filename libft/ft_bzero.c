/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:04:44 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:04:53 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_bzero(void *str, size_t num)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < num)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
