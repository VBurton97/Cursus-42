/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:23:28 by vburton           #+#    #+#             */
/*   Updated: 2022/11/09 15:42:40 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, \
	const char *src, size_t dstsize)
{
	size_t	i;
	size_t	taille_src;

	i = 0;
	taille_src = ft_strlen((char *)src);
	if (dstsize != 0)
	{
		while (i < taille_src && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (taille_src);
}
