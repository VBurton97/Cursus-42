/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:25:54 by vburton           #+#    #+#             */
/*   Updated: 2022/11/15 09:47:20 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size == SIZE_MAX && count == SIZE_MAX)
		return (NULL);
	res = malloc(size * count);
	if (res == NULL)
		return (res);
	ft_bzero(res, size * count);
	return (res);
}
