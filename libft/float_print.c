/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:27:44 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 13:27:45 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

static char	*build_float(t_arg *arg)
{
	char		*num;
	long double	f;
	int			precision;

	f = get_float(arg);
	if (F(F_PRECISE))
		precision = arg->precision;
	else
		precision = (arg->precision) ? arg->precision : 6;
	if (f != f)
		num = (ft_isupper(arg->conv)) ? "NAN" : "nan";
	else if (f == 1.0 / 0.0)
		num = (ft_isupper(arg->conv)) ? "INF" : "inf";
	else
		num = pf_ftoa(f, precision, 10.0);
	set_prefix(arg, 10, num);
	return (num);
}

int			print_float(t_arg *arg)
{
	char	*num;
	int		len;
	int		prefix_len;
	int		pad;
	int		out_len;

	num = build_float(arg);
	len = ft_strlen(num);
	prefix_len = ft_strlen(arg->prefix);
	out_len = 0;
	pad = arg->width - len - prefix_len;
	if (!F(F_MINUS))
		out_len += write_pad(pad, ' ');
	out_len += write(1, arg->prefix, prefix_len);
	out_len += write(1, num, len);
	if (F(F_MINUS))
		out_len += write_pad(pad, ' ');
	if (!F(F_SPECIAL))
		free(num);
	return (out_len);
}
