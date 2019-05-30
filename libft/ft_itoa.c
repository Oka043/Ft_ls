/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:05:39 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:05:42 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdlib.h>

char	*ft_itoa(intmax_t n)
{
	char		*num;
	int			sign;
	int			len;
	intmax_t	tmp;

	sign = (n < 0) ? -1 : 1;
	len = (n == 0) + (sign < 0);
	tmp = n;
	while (tmp != 0 && ++len)
		tmp /= 10;
	if (!(num = (char *)malloc(len + 1)))
		return (NULL);
	num += len;
	*num-- = '\0';
	if (n == 0)
		*num-- = '0';
	while (n != 0)
	{
		*num-- = (char)(((n % 10) * sign) + '0');
		n /= 10;
	}
	if (sign < 0)
		*num-- = '-';
	return (++num);
}
