/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:24:21 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:24:37 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*n1;
	unsigned char	*n2;

	i = 0;
	n1 = (unsigned char *)s1;
	n2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	while (n1[i] || n2[i])
	{
		if (n1[i] != n2[i])
			return (0);
		i++;
	}
	return (1);
}
