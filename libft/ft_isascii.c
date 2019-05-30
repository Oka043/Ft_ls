/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:49:52 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:04:06 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int n)
{
	if (n >= 0 && n < 128)
		return (1);
	else
		return (0);
}
