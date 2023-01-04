/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:22:25 by vburton           #+#    #+#             */
/*   Updated: 2023/01/04 17:37:06 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitbis(char const *s, char **res, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
		{
			if (s[i + j + 1] == '\0' || s[i + j +1] == c)
				res[x++] = ft_substr(s, i, j + 1);
			j++;
		}
		i = i + j;
	}
	res[x] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c || (s[i] == '\0' && s[i - 1] != c))
			len++;
	}
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_splitbis(s, res, c);
	return (res);
}
