/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:02:17 by vburton           #+#    #+#             */
/*   Updated: 2022/11/16 20:57:45 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	countdigit(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	if (n == INT_MIN)
		i = 11;
	else
	{
		if (n < 0)
			n = n * -1;
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		count;
	long	nbis;
	char	*res;

	count = countdigit(n);
	nbis = n;
	res = malloc(sizeof(char) * (count + 1));
	if (!res)
		return (NULL);
	res[count--] = '\0';
	if (n < 0)
		nbis = nbis * -1;
	while (count >= 0)
	{
		res[count--] = nbis % 10 + 48;
		nbis = nbis / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
