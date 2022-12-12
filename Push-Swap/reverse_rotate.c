/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:29:25 by vburton           #+#    #+#             */
/*   Updated: 2022/12/12 19:22:12 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(t_tab *tab)
{
	int	i;
	int cln;
	int	start;

	i = tab->pos_last_num;
	while (i > 0)
	{
		cln = tab->tab[i - 1];
		tab->tab[i - 1] = tab->tab[i];
		tab->tab[i] = cln;
		i--;
	}
	ft_printf("rr%c\n", tab->colonne);
}

void ft_reverse_rotate_rrr(t_tab *tab_a, t_tab *tab_b)
{
	ft_rotate(tab_a);
	ft_rotate(tab_b);
	ft_printf("rrr\n");
}
