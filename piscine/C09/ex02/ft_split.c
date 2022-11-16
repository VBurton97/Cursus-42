/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:14:44 by vburton           #+#    #+#             */
/*   Updated: 2022/09/20 16:13:37 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include<stdio.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset) && str[i])
			i++;
		while (!(is_charset(str[i], charset)) && str[i])
			i++;
		if (!(is_charset(str[i - 1], charset)))
			count_word++;
	}
	return (count_word);
}

int	ft_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !(is_charset(str[i], charset)))
		i++;
	return (i);
}

void	*ft_strdup(char *str, char *charset)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_len(str, charset);
	dest = malloc(sizeof(char) * (len + 1));
	if (! dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**res;

	i = -1;
	j = 0;
	if (str[0] == '\0')
		res = malloc(sizeof(char *) * 1);
	else
		res = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (! res)
		return (NULL);
	if (charset[0] == '\0')
		res[0] = str;
	while (str[++i])
	{
		if (!(is_charset(str[i], charset)))
		{
			res[j] = ft_strdup(&str[i], charset);
			i = i + ft_len(res[j], charset);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
