/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:59:40 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:32:59 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				res;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)s1;
	n2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	while (n1[i] || n2[i])
	{
		if (n1[i] > n2[i] || n1[i] < n2[i])
		{
			res = n1[i] - n2[i];
			return (res);
		}
		else
			i++;
	}
	return (0);
}
