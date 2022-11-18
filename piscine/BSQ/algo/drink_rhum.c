/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:48:15 by vburton           #+#    #+#             */
/*   Updated: 2022/09/20 18:35:35 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	drink_rhum(char **tab, t_stock treasure)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		len;

	x = treasure.x;
	y = treasure.y;
	len = treasure.len_max;
	i = 0;
	if (tab[x][y] == treasure.obs)
		return ;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			tab[x + i][y + j] = treasure.fill;
			j++;
		}
		i++;
	}
}
