/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:39:13 by vburton           #+#    #+#             */
/*   Updated: 2022/12/14 18:17:26 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_second_sort_bis(t_tab *tab_a, t_tab *tab_b)
{
	int	a;
	int	b;
	int	i;
	int	j;
	int	y;
	int	pos;

	b = tab_b->pos_last_num / 2;
	if (tab_a->tab[0] > tab_a->tab[1])
		ft_swap(tab_a);
	while (tab_b->pos_last_num >= 0)
	{
		i = 0;
		j = tab_b->pos_last_num + 1;
		y = 0;
		pos = 0;
		while (y <= j)
		{
			if (tab_b->tab[y] > tab_b->tab[pos])
				pos = y;
			y++;;
		}
		a = tab_b->pos_last_num - pos + 1;
		if (pos > (tab_b->pos_last_num / 2))
		{
			while (i < a)
			{
				ft_reverse_rotate(tab_b);
				i++;
			}
		}
		else
		{
			while (pos > 0)
			{
				ft_rotate(tab_b);
				pos--;
			}
		}
		ft_push_a(tab_a, tab_b);
	}
}

void	ft_first_sort_bis(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
{
	int	j;
	int	s;
	int	median;
	int	mid;

	mid = tab_a->pos_last_num / 2;
	while (tab_a->pos_last_num > 1)
	{
		s = (tab_a->pos_last_num + 1)/ 2;
		median = tab_sort[tab_a->size - s];
		if (median == tab_sort[tab_a->size - 1])
			median--;
		while (0 < s)
		{
			j = 0;
			if (tab_a->tab[0] < median)
			{
				ft_push_b(tab_a, tab_b);
				//ft_display(tab_a, tab_b);
				s--;
			}
			else if (tab_a->tab[tab_a->pos_last_num] < median)
			{
				ft_reverse_rotate(tab_a);
				ft_push_b(tab_a, tab_b);
				//ft_display(tab_a, tab_b);
				if (tab_b->tab[0] < tab_b->tab[1])
					ft_swap(tab_b);
				s--;
			}
			else
				ft_rotate(tab_a);
		}
	}
}
