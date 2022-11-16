/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:12:19 by vburton           #+#    #+#             */
/*   Updated: 2022/11/16 20:58:09 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, \
	const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	if (dest == NULL && dstsize == 0)
		return (0);
	len_dest = ft_strlen((char *)dest);
	len_src = ft_strlen((char *)src);
	if (dstsize < len_dest || dstsize == 0)
		return (dstsize + len_src);
	while (src[i] != '\0' && i + len_dest < dstsize - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
