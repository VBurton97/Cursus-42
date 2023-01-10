/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:29:25 by vburton           #+#    #+#             */
/*   Updated: 2023/01/10 15:37:44 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_tab *tab, int r)
{
	int	i;
	int	cln;

	i = tab->pos_last_num;
	while (i > 0)
	{
		cln = tab->tab[i - 1];
		tab->tab[i - 1] = tab->tab[i];
		tab->tab[i] = cln;
		i--;
	}
	if (r == 1)
		ft_printf("rr%c\n", tab->colonne);
}

void	ft_reverse_rotate_rrr(t_tab *tab_a, t_tab *tab_b)
{
	ft_reverse_rotate(tab_a, 0);
	ft_reverse_rotate(tab_b, 0);
	ft_printf("rrr\n");
}
