/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:15:13 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/19 20:20:14 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

typedef struct s_stock
{
	int		x;
	int		y;
	int		len_max;
	int		length;
	int		height;
	char	obs;
	char	fill;
}	t_stock;

void	drink_rhum(char **tab, t_stock treasure);
void	sailing_to_treasure(char **treasure_map);
void	long_seeker(char **treasure_map, t_stock *treasure);
void	ft_show_tab(t_stock par);
int		shovel_digging(t_stock treasure, char **treasure_map);
t_stock	treasure_chest(char **tab);

#endif
