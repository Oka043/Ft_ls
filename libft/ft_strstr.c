/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:12:12 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:44:32 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int				i;
	int				cnt;
	int				j;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)haystack;
	n2 = (unsigned char *)needle;
	cnt = 0;
	i = 0;
	while (n2[cnt])
		cnt++;
	while (n1[i] || cnt == 0)
	{
		j = 0;
		while (n1[i + j] == n2[j] || cnt == 0)
		{
			if (j == cnt - 1 || cnt == 0)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
