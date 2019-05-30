/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:39:31 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:39:35 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!(*alst || alst || del))
		return ;
	if (*alst || alst || del)
	{
		del(((*alst)->content), (*alst)->content_size);
		free(*alst);
		*alst = 0;
	}
}
