/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:39:13 by vburton           #+#    #+#             */
/*   Updated: 2023/01/10 15:38:13 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_up(t_tab *tab)
{
	int	i;

	i = 0;
	while (i <= tab->pos_last_num)
	{
		tab->tab[i] = tab->tab[i + 1];
		i++;
	}
	tab->tab[tab->pos_last_num] = 0;
	tab->pos_last_num -= 1;
}

void	ft_down(t_tab *tab)
{
	int	i;

	i = tab->pos_last_num;
	while (i >= 0)
	{
		tab->tab[i + 1] = tab->tab[i];
		i--;
	}
	tab->pos_last_num += 1;
}

void	ft_push_a(t_tab *tab_a, t_tab *tab_b)
{
	if (tab_b->tab[0] == 0)
		return ;
	ft_down(tab_a);
	tab_a->tab[0] = tab_b->tab[0];
	ft_up(tab_b);
	ft_printf("pa\n");
}

void	ft_push_b(t_tab *tab_a, t_tab *tab_b)
{
	if (tab_a->tab[0] == 0)
		return ;
	ft_down(tab_b);
	tab_b->tab[0] = tab_a->tab[0];
	ft_up(tab_a);
	ft_printf("pb\n");
}
