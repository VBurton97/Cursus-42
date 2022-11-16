/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:39:35 by vburton           #+#    #+#             */
/*   Updated: 2022/11/15 09:50:35 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if ((ft_strchr(set, (int)s1[i])) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_end(char const *s1, char const *set)
{
	int	j;

	j = ft_strlen((char *)s1);
	while (j > 0)
	{
		if ((ft_strchr(set, (int)s1[j])) == 0)
			break ;
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = ft_start(s1, set);
	j = ft_end(s1, set);
	len = j - i + 1;
	if (i > j)
		return (ft_strdup(""));
		res = ft_substr(s1, i, len);
	return (res);
}
