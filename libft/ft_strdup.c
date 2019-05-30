/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:39:34 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:39:38 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int		i;
	char	*t;
	int		size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	t = (char *)malloc(size + 1);
	if (t == 0)
		return (0);
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
