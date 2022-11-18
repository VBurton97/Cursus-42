/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_treasure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:50 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/20 18:35:56 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "srcs.h"

void	sailing_to_treasure(char **treasure_map)
{
	t_stock	treasure;

	treasure = treasure_chest(treasure_map);
	long_seeker(treasure_map, &treasure);
	drink_rhum(treasure_map, treasure);
}

t_stock	treasure_chest(char **treasure_map)
{
	t_stock	treasure;
	int		len;

	len = ft_strlen(treasure_map[0]);
	treasure.x = 0;
	treasure.y = 0;
	treasure.length = length(treasure_map);
	treasure.height = height(treasure_map);
	treasure.len_max = find_len_max(treasure_map);
	treasure.obs = treasure_map[0][len - 2];
	treasure.fill = treasure_map[0][len - 1];
	return (treasure);
}

void	long_seeker(char **treasure_map, t_stock *treasure)
{
	int		len_max;
	int		i;
	int		j;

	len_max = (*treasure).len_max;
	i = 1;
	while (treasure_map[i] && len_max + i - 1 <= (*treasure).height)
	{
		j = 0;
		while (treasure_map[i][j] && len_max + j <= (*treasure).length)
		{
			treasure -> x = i;
			treasure -> y = j;
			if (shovel_digging(*treasure, treasure_map))
				return ;
			j++;
		}
		i++;
	}
	if (len_max - 1 == 0)
		return ;
	treasure -> len_max = len_max - 1;
	long_seeker(treasure_map, treasure);
}

int	shovel_digging(t_stock treasure, char **treasure_map)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	len;

	x = treasure.x;
	y = treasure.y;
	len = treasure.len_max;
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (treasure_map[x + i][y + j] == treasure.obs)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
