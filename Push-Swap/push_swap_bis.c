/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:39:13 by vburton           #+#    #+#             */
/*   Updated: 2022/12/19 22:38:19 by vburton          ###   ########.fr       */
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

void	ft_second_sort_bis_bis(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
{
	int	a;
	int	c;
	int	y;
	int	i;
	int	n;
	int	t;
	int	min;
	int	max;
	int	pivot;

	c = 10;
	a = c - 1;
	y = 0;
	while (a >= 0)
	{
		pivot = tab_sort[(tab_a->size / c) * a - 1];
		min = tab_sort[(tab_a->size / c) * a];
		i = tab_a->size / c;
		while (i >= 0)
		{
			n = 0;
			max = ft_is_bigger(tab_b);
			t = tab_b->pos_last_num;
			if (max > tab_b->pos_last_num / 2)
			{
				while (t - n >= max)
				{
					if (tab_b->tab[0] == min)
					{
						ft_push_a(tab_a, tab_b);
						ft_rotate(tab_a, 1);
						min = tab_sort[((tab_a->size / c) * a) + (tab_a->size / c) - i];
						y++;
					}
					if (t - n >= max)
						ft_reverse_rotate(tab_b, 1);
					n++;
				}
			}
			else
			{
				while (n < max)
				{
					if (tab_b->tab[0] == min)
					{
						ft_push_a(tab_a, tab_b);
						ft_rotate(tab_a, 1);
						min = tab_sort[((tab_a->size / c) * a) + (tab_a->size / c) - i];
						y++;
						n++;
					}
					if (n < max)
						ft_rotate(tab_b, 1);
					n++;
				}
			}
			// ft_printf("min = %d\n", min);
			if (tab_b->tab[0] < tab_a->tab[tab_a->pos_last_num - y + 1])
			{
				while (y > 0)
				{
					ft_reverse_rotate(tab_a, 1);
					y--;
				}
				ft_push_a(tab_a, tab_b);
			}
			else
				ft_push_a(tab_a, tab_b);
			i--;
		}
		a--;
	}
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
	int	y;
	int	c;
	int	pivot;

	a = 1;
	x = 0;
	y = 0;
	c = 10;
	while (a <= c)
	{
		pivot = tab_sort[tab_a->size / c * a - 1];
		i = tab_a->size / c - x;
		while (x > 0)
		{
			ft_reverse_rotate(tab_b, 1);
			x--;
		}
		// printf("i = %d\n", i);
		while (i > 0)
		{
			if (tab_a->tab[0] <= pivot)
			{
				ft_push_b(tab_a, tab_b);
				i--;
			}
			else if (tab_a->tab[0] > pivot && tab_a->tab[0] < tab_sort[(tab_a->size / (2 * c)) * (2 * a + 1) - 1])
			{
				ft_push_b(tab_a, tab_b);
				y++;
				x++;
			}
			else if (tab_a->tab[0] > tab_a->tab[tab_a->pos_last_num])
				ft_rotate(tab_a, 1);
			else if (tab_a->tab[0] > pivot)
				ft_rotate(tab_a, 1);
			else if (tab_a->tab[0] >= pivot && tab_b->tab[0] > pivot && tab_b->tab[0] < tab_sort[(tab_a->size / (2 * c)) * (2 * a + 1) - 1])
				ft_rotate_rr(tab_a, tab_b);
			else if (tab_a->tab[0] >= pivot)
				ft_rotate(tab_a, 1);
			if (tab_a->tab[ft_find_next(tab_a, tab_sort[(tab_a->size / (2 * c)) * (2 * a + 1) - 1])] <= pivot)
			{
				if (a == 1 && tab_b->tab[0] > pivot)
					y = 0;
				while (y >= 0)
				{
					if (tab_a->tab[0] > tab_sort[(tab_a->size / (2 * c)) * (2 * a + 1) - 1])
						ft_rotate_rr(tab_a, tab_b);
					else
						ft_rotate(tab_b, 1);
					y--;
				}

			}
		}
		a++;
	}
}
