/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:56:20 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:04:28 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int n)
{
	if (n <= 122 && n >= 97)
		return (n - 32);
	return (n);
}
