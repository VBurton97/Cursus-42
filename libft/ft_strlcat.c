/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:12:19 by vburton           #+#    #+#             */
/*   Updated: 2022/11/09 15:42:40 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, \
	const char *src, size_t dstsize)
{
	size_t	i;
	size_t	t;
	size_t	t_dest;
	size_t	t_src;

	i = 0;
	if (dest == NULL && dstsize == 0)
		return (0);
	t_dest = ft_strlen((char *)dest);
	t_src = ft_strlen((char *)src);
	t = dstsize - 1;
	if (dstsize < t_dest || dstsize == 0)
		return (dstsize + t_src);
	while (src[i] != '\0' && i + t_dest < t)
	{
		dest[t_dest + i] = src[i];
		i++;
	}
	dest[t_dest + i] = '\0';
	return (t_dest + t_src);
}
