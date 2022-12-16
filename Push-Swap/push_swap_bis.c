/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:39:13 by vburton           #+#    #+#             */
/*   Updated: 2022/12/16 16:01:57 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_bigger(t_tab *tab)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (i <= tab->pos_last_num)
	{
		if (tab->tab[i] > tab->tab[big])
			big = i;
		i++;
	}
	return (big);
}

int	ft_find_next(t_tab *tab, int pivot)
{
	int	i;
	int	pos;

	i = 0;
	pos = i;
	while (i < tab->pos_last_num)
	{
		if (tab->tab[i] <= pivot)
			return (i);
		i++;
	}
	return (0);
}

void	ft_second_sort_bis(t_tab *tab_a, t_tab *tab_b)
{
	int a;

	while (tab_b->pos_last_num >= 0)
	{
		// ft_display(tab_a, tab_b);
		a = ft_is_bigger(tab_b);
		if (a == 0)
			ft_push_a(tab_a, tab_b);
		else
		{
			if (a >= (tab_b->pos_last_num / 2))
			{
				while (tab_b->pos_last_num - a >= 0)
				{
					ft_reverse_rotate(tab_b, 1);
					a++;
				}
			}
			else
			{
				while (a > 0)
				{
					ft_rotate(tab_b, 1);
					a--;
				}
			}
			ft_push_a(tab_a, tab_b);
		}
	}
}

void	ft_first_sort_bis(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
{
	int	i;
	int	a;
	int	x;
	int	pivot;

	a = 1;
	x = 0;
	while (a <= 5)
	{
		pivot = tab_sort[tab_a->size / 5 * a - 1];
		i = tab_a->size / 5 - x;
		// printf("i = %d\n", i);
		while (i > 0)
		{
			// printf("pivot = %d\n", pivot);
			// ft_display(tab_a, tab_b);
			// printf("i = %d\n", i);
			if (tab_a->tab[0] > tab_a->tab[1] && tab_b->tab[0] < tab_b->tab[1])
				ft_swap_ss(tab_a, tab_b);
			else if (tab_b->tab[0] < tab_b->tab[1])
				ft_swap(tab_b, 1);
			if (tab_a->tab[0] <= pivot)
			{
				ft_push_b(tab_a, tab_b);
				i--;
			}
			// else if (tab_a->tab[0] > pivot && tab_a->tab[0] < tab_sort[tab_a->size / 5 * (a + 1) - 1])
			// {
			// 	ft_push_b(tab_a, tab_b);
			// 	if (tab_a->tab[0] > tab_sort[tab_a->size / 5 * (a + 1) - 1])
			// 		ft_rotate_rr(tab_a, tab_b);
			// 	else
			// 		ft_rotate(tab_b, 1);
			// 	x++;
			// }
			if (tab_a->tab[0] > tab_a->tab[tab_a->pos_last_num])
				ft_rotate(tab_a, 1);
			else if (tab_a->tab[0] > pivot && tab_b->tab[0] < tab_b->tab[tab_b->pos_last_num])
				ft_rotate_rr(tab_a, tab_b);
			else if (tab_b->tab[0] < tab_b->tab[tab_b->pos_last_num])
				ft_rotate(tab_b, 1);
			else if (tab_a->tab[0] >= pivot)
				ft_rotate(tab_a, 1);
		}
		a++;
	}
}
