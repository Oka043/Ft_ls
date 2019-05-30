/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:34:21 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:34:23 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

# define F(f) (arg->flags & f)
# define BASE_KEY "0123456789abcdef"

typedef struct	s_arg
{
	va_list	*ap;
	char	conv;
	char	prefix[3];
	int		flags;
	int		width;
	int		precision;
}				t_arg;

typedef struct	s_conv
{
	char	specifier;
	int		(*handle)(t_arg *);
}				t_conv;

enum	e_flags
{
	F_H = 1,
	F_HH = 1 << 1,
	F_L = 1 << 2,
	F_LD = 1 << 3,
	F_LL = 1 << 4,
	F_J = 1 << 5,
	F_Z = 1 << 6,
	F_PRECISE = 1 << 7,
	F_MINUS = 1 << 8,
	F_PLUS = 1 << 9,
	F_SPACE = 1 << 10,
	F_ZERO = 1 << 11,
	F_HASH = 1 << 12,
	F_SPECIAL = 1 << 13,
	F_ESCAPE = 1 << 14,
	F_UTF = 1 << 15
};

/*
** char_print.c
*/

int				print_char(t_arg *arg);
int				print_percent(t_arg *arg);
int				print_str(t_arg *arg);

/*
** char_util.c
*/

int				ft_utflen(wchar_t *ws, int n);
int				ft_wcnlen(wchar_t *ws, int n);
void			ft_wctouc(char *dst, wchar_t *src, int n);
void			ft_tout_str(char *dst, wchar_t *src, int n);

/*
** float_print.c
*/

int				print_float(t_arg *arg);

/*
** float_util.c
*/

long double		get_float(t_arg *arg);
char			*pf_ftoa(long double f, int precision, float base);

/*
** ft_printf.c
*/

int				dispatch(t_arg *arg);
int				ft_printf(const char *format, ...);
void			set_prefix(t_arg *arg, int base, char *num);
int				write_pad(int size, char c);

/*
** ft_printf_pars.c
*/

int				handle_arg(const char **fmt, va_list *ap, int len);

/*
** int_handlers.c
*/

int				print_d(t_arg *arg);
int				print_o(t_arg *arg);
int				print_p(t_arg *arg);
int				print_u(t_arg *arg);
int				print_x(t_arg *arg);

/*
** int_handlers_deprec.c
*/

int				print_ld_deprec(t_arg *arg);
int				print_to_deprec(t_arg *arg);
int				print_ul_deprec(t_arg *arg);

/*
** int_print.c
*/

int				print_int(t_arg *arg, int base, t_bool is_signed);

/*
** int_util.c
*/

intmax_t		get_int(t_arg *arg);
uintmax_t		get_uint(t_arg *arg);
char			*pf_itoa(t_arg *arg, intmax_t n, int base);
char			*pf_uitoa(uintmax_t un, int base);

extern const t_conv	g_disp[];
extern const int	g_disp_count;
#endif
