/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:11:15 by vburton           #+#    #+#             */
/*   Updated: 2022/12/16 12:12:32 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_tab *tab, int r)
{
	int	i;
	int cln;

	i = 0;
	while (i < tab->pos_last_num)
	{
		cln = tab->tab[i + 1];
		tab->tab[i + 1] = tab->tab[i];
		tab->tab[i] = cln;
		i++;
	}
	if (r == 1)
		ft_printf("r%c\n", tab->colonne);
}

void ft_rotate_rr(t_tab *tab_a, t_tab *tab_b)
{
	ft_rotate(tab_a, 0);
	ft_rotate(tab_b, 0);
	ft_printf("rr\n");
}
