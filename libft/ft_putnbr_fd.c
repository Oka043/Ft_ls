/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:55:27 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:36:39 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
