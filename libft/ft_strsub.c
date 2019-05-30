/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:37:24 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:37:27 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strsub(char const *s, unsigned int star, size_t len)
{
	char		*result;
	size_t		j;

	j = 0;
	if (!s)
		return (0);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (j < len && s[star])
		result[j++] = s[star++];
	result[j] = '\0';
	return (result);
}
