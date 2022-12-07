/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:11:15 by vburton           #+#    #+#             */
/*   Updated: 2022/12/07 15:28:26 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_tab *tab)
{
	int	i;
	int cln;
	int	start;

	i = 0;
	while (i < tab->pos_last_num - 1)
	{
		cln = tab->tab[i + 1];
		tab->tab[i + 1] = tab->tab[i];
		tab->tab[i] = cln;
		i++;
	}
}

void ft_rotate_rr(t_tab *tab_a, t_tab *tab_b)
{
	ft_rotate(tab_a);
	ft_rotate(tab_b);
}