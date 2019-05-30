/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:40:04 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:40:12 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstadd(t_list **alst, t_list *lst)
{
	if (!alst || !lst)
		return ;
	if (alst && lst)
	{
		lst->next = *alst;
		*alst = lst;
	}
}
