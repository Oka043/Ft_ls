/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:38:31 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:38:34 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*r;

	r = (t_list*)malloc(sizeof(t_list));
	if (!r)
		return (0);
	if (content == 0)
	{
		r->content = 0;
		r->content_size = 0;
	}
	else
	{
		r->content = malloc(content_size);
		ft_memcpy(r->content, content, content_size);
		r->content_size = content_size;
	}
	r->next = 0;
	return (r);
}
