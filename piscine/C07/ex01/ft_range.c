/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:35:24 by vburton           #+#    #+#             */
/*   Updated: 2022/09/15 19:43:48 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_diff(int min, int max)
{
	int	n;

	n = 0;
	if (max < 0)
		return ((min * -1) + max);
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int	n;
	int	i;
	int	*tab;

	i = 0;
	tab = NULL;
	if (max <= min)
		return (tab);
	n = ft_diff(min, max);
	tab = malloc(sizeof(int) * n);
	if (! tab)
		return (0);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	tab[i] = '\0';
	return (tab);
}
