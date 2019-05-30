/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handlers_deprec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:28:33 by olaktion          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:54 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	print_ld_deprec(t_arg *arg)
{
	arg->flags = ((arg->flags >> 6) << 6) | F_L;
	return (print_int(arg, 10, TRUE));
}

int	print_to_deprec(t_arg *arg)
{
	arg->flags = ((arg->flags >> 6) << 6) | F_L;
	return (print_int(arg, 8, FALSE));
}

int	print_ul_deprec(t_arg *arg)
{
	arg->flags = ((arg->flags >> 6) << 6) | F_L;
	return (print_int(arg, 10, FALSE));
}
