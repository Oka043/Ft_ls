/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:02:03 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:48:27 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

static size_t	ft_cntword(char const *str, char x)
{
	size_t	j;
	size_t	wd;

	j = 0;
	wd = 0;
	while (str[j])
	{
		while (str[j] == x && str[j])
			j++;
		if (str[j])
			wd++;
		while (str[j] != x && str[j])
			j++;
	}
	return (wd);
}

static size_t	ft_wordlen(char const *str, char x)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = 0;
	while (str[j] && str[j] != x)
	{
		len++;
		j++;
	}
	return (len);
}

char			**ft_strsplit(char const *str, char x)
{
	size_t		j;
	size_t		t;
	char		**ar;

	j = 0;
	t = 0;
	if (!str || !x)
		return (0);
	ar = (char **)malloc(sizeof(char *) * (ft_cntword(str, x) + 2));
	if (!ar)
		return (0);
	while (str[j] && t < ft_cntword(str, x))
	{
		while (str[j] == x && str[j])
			j++;
		ar[t] = (char *)malloc(sizeof(char) * (ft_wordlen(&str[j], x) + 1));
		if (!ar[t])
			return (0);
		ft_strncpy(ar[t], str + j, ft_wordlen(str + j, x));
		ar[t][ft_wordlen(str + j, x)] = '\0';
		j += ft_wordlen(str + j, x);
		t++;
	}
	ar[t] = 0;
	return (ar);
}
