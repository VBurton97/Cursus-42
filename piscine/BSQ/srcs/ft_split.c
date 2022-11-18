/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:31:52 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/18 15:38:43 by fnamboti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

int	is_a_sep(char c, char *charset)
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

int	ft_len_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !(is_a_sep(str[i], charset)))
		i++;
	return (i);
}

int	word_counting(char *str, char *charset)
{
	int	i;
	int	wd_count;

	i = 0;
	wd_count = 0;
	while (str[i] && is_a_sep(str[i], charset))
			i++;
	while (str[i])
	{
		while (str[i] && is_a_sep(str[i], charset))
			i++;
		while (!is_a_sep(str[i], charset) && str[i])
			i++;
		if (!is_a_sep(str[i - 1], charset))
			wd_count++;
		i++;
	}
	return (wd_count);
}

char	*ft_strdup2(char *str, char *charset)
{
	int		i;
	int		len_word;
	char	*word;

	i = 0;
	len_word = ft_len_word(str, charset);
	word = malloc(sizeof(char) * len_word + 1);
	if (!(word))
		return (NULL);
	while (i < len_word)
	{	
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**tab_word;

	tab_word = malloc(sizeof(char *) * (word_counting(str, charset) + 1));
	if (!(tab_word))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (!is_a_sep(str[i], charset))
		{
			tab_word[j] = ft_strdup2(&str[i], charset);
			if (!(tab_word[j]))
			{
				free_tab(tab_word);
				free(tab_word);
				return (NULL);
			}
			i += ft_len_word(tab_word[j++], charset);
		}
	}
	tab_word[j] = NULL;
	return (tab_word);
}
