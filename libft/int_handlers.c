/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:28:50 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 13:28:51 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int			print_d(t_arg *arg)
{
	return (print_int(arg, 10, TRUE));
}

int			print_o(t_arg *arg)
{
	return (print_int(arg, 8, FALSE));
}

int			print_p(t_arg *arg)
{
	arg->flags |= F_HASH;
	return (print_int(arg, 16, FALSE));
}

int			print_u(t_arg *arg)
{
	return (print_int(arg, 10, FALSE));
}

int			print_x(t_arg *arg)
{
	return (print_int(arg, 16, FALSE));
}
