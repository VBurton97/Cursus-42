/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:57:50 by vburton           #+#    #+#             */
/*   Updated: 2022/11/15 12:00:18 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)ft_strlen((char *)&s[start]) < len)
		len = ft_strlen((char *)&s[start]);
	if ((int)start > ft_strlen((char *)s))
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
