/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:35:57 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:36:01 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

static int		ft_end(char const *s)
{
	int		i;
	int		cnt;
	int		end;

	cnt = 0;
	end = 0;
	i = ft_strlen(s);
	while (s[--i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			cnt++;
		else if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && cnt == 0)
			end++;
	return (end);
}

static int		ft_ere(char const *s)
{
	int		i;
	int		ere;
	int		cnt;

	ere = 0;
	i = -1;
	cnt = 0;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			cnt++;
		else if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && cnt == 0)
			ere++;
	return (ere);
}

char			*ft_strtrim(char const *s)
{
	char	*tmp;
	int		ere;
	int		end;
	int		len;

	if (!s)
		return (0);
	ere = ft_ere(s);
	end = ft_end(s);
	len = ft_strlen(s) - end - ere;
	if (len < 0)
		return (ft_strdup(""));
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp = ft_strsub(s, ere, len);
	return (tmp);
}
