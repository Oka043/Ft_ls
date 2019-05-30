/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:27:22 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 13:27:24 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

static void	ft_tout(char *dst, wchar_t *src, int size)
{
	if (!size)
		*dst = *src;
	else
	{
		if (size < 2)
			*dst++ = 0xC0 | (*src >> 6);
		else if (size < 3)
			*dst++ = 0xE0 | (*src >> 12);
		else
			*dst++ = 0xF0 | (*src >> 18);
		while (size--)
			*dst++ = 0x80 | ((*src >> (size * 6)) & 0x3F);
	}
}

int			ft_utflen(wchar_t *ws, int n)
{
	int	len;
	int	size;

	len = 0;
	while (*ws)
	{
		if (*ws <= 0x7F)
			size = 1;
		else if (*ws <= 0x7FF)
			size = 2;
		else if (*ws <= 0xFFFF)
			size = 3;
		else if (*ws <= 0x10FFFF)
			size = 4;
		else
			return (-1);
		if (len + size > n)
			break ;
		len += size;
		ws++;
	}
	return (len);
}

/*
** For C/POSIX locale
*/

int			ft_wcnlen(wchar_t *ws, int n)
{
	int	len;

	len = 0;
	while (ws[len] && len < n)
	{
		if (ws[len] > 0xFF)
			return (-1);
		len++;
	}
	return (len);
}

void		ft_wctouc(char *dst, wchar_t *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = (char)src[i];
		i++;
	}
}

void		ft_tout_str(char *dst, wchar_t *src, int n)
{
	int	len;
	int	size;

	len = 0;
	while (*src)
	{
		if (*src <= 0x7F)
			size = 1;
		else if (*src <= 0x7FF)
			size = 2;
		else if (*src <= 0xFFFF)
			size = 3;
		else if (*src <= 0x10FFFF)
			size = 4;
		else
			break ;
		if (len + size > n)
			break ;
		ft_tout(dst, src++, size - 1);
		dst += size;
		len += size;
	}
}
