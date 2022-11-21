/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:04:24 by vburton           #+#    #+#             */
/*   Updated: 2022/11/21 21:17:29 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len_s1;
	char	*dup;

	i = 0;
	len_s1 = ft_strlen((char *)s1);
	dup = malloc(sizeof(char) * len_s1 + 1);
	if (!dup)
		return (NULL);
	if (len_s1 == 0)
	{
		dup[i] = '\0';
		return (dup);
	}
	while (i < len_s1)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size_tot;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((size_tot = ft_strlen((char *)s1) + ft_strlen((char *)s2)) >= SIZE_MAX)
		return (NULL);
	res = malloc(sizeof(char) * (size_tot + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)ft_strlen((char *)&s[start]) < len)
		len = ft_strlen((char *)&s[start]);
	if ((size_t)start > ft_strlen((char *)s))
	{
		sub = malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc(sizeof(char const) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

