/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:12:13 by vburton           #+#    #+#             */
/*   Updated: 2022/09/15 21:58:05 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	taille;

	i = 0;
	taille = max - min;
	if (min >= max)
	{
		(*range) = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * taille);
	if (! range)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (taille);
}
