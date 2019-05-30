/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:57:54 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:53:14 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_memalloc(size_t size)
{
	void		*s;

	s = malloc(size);
	if (!s)
		return (0);
	s = ft_bzero(s, size);
	return (s);
}
