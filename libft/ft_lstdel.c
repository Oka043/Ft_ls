/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:39:44 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:39:54 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *l;
	t_list *lst;

	if (!alst || !(*alst) || !del)
		return ;
	l = *alst;
	while (l)
	{
		lst = l->next;
		del(l->content, l->content_size);
		free(l);
		l = lst;
	}
	*alst = 0;
}
