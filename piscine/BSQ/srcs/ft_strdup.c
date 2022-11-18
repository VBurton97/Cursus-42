/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:40:29 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/13 20:20:29 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*src_copy;

	i = 0;
	while (src[i])
		i++;
	len = i;
	src_copy = malloc(sizeof(char) * len + 1);
	if (!(src_copy))
		return (NULL);
	i = 0;
	while (src[i])
	{	
		src_copy[i] = src[i];
		i++;
	}
	src_copy[i] = 0;
	return (src_copy);
}
