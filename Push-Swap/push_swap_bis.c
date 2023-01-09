/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:39:13 by vburton           #+#    #+#             */
/*   Updated: 2022/12/29 19:25:15 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_second_sort(t_tab *tab_a, t_tab *tab_b)
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

void ft_first_sort_last_if(t_tab *tab_a, t_tab *tab_b, long *tab_sort, t_data *data)
{
	if (data->a == 1 && tab_b->tab[0] > data->pivot)
		data->y = 0;
	while (data->y >= 0)
	{
		if (tab_a->tab[0] > tab_sort[(tab_a->size / (2 * data->c)) * (2 * data->a + 1) - 1])
			ft_rotate_rr(tab_a, tab_b);
		else
			ft_rotate(tab_b, 1);
		data->y--;
	}
}

void ft_first_sort_bis(t_tab *tab_a, t_tab *tab_b, long *tab_sort, t_data *data)
{
	while (data->i > 0)
	{
		if (tab_a->tab[0] <= data->pivot)
		{
			ft_push_b(tab_a, tab_b);
			data->i--;
		}
		else if (tab_a->tab[0] > data->pivot && tab_a->tab[0] < tab_sort[(tab_a->size / (2 * data->c)) * (2 * data->a + 1) - 1])
		{
			ft_push_b(tab_a, tab_b);
			data->y++;
			data->x++;
		}
		else if (tab_a->tab[0] > data->pivot)
			ft_rotate(tab_a, 1);
		else if (tab_a->tab[0] >= data->pivot && tab_b->tab[0] > data->pivot && tab_b->tab[0] < tab_sort[(tab_a->size / (2 * data->c)) * (2 * data->a + 1) - 1])
			ft_rotate_rr(tab_a, tab_b);
		if (tab_a->tab[ft_find_next(tab_a, tab_sort[(tab_a->size / (2 * data->c)) * (2 * data->a + 1) - 1])] <= data->pivot)
		{
			ft_first_sort_last_if(tab_a, tab_b, tab_sort, data);
		}
	}
}

void	ft_first_sort(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
{
	t_data	data;

	data.a = 1;
	data.x = 0;
	data.y = 0;
	data.c = 10;
	while (data.a <= data.c)
	{
		data.pivot = tab_sort[tab_a->size / data.c * data.a - 1];
		data.i = tab_a->size / data.c - data.x;
		while (data.x > 0)
		{
			ft_reverse_rotate(tab_b, 1);
			data.x--;
		}
		ft_first_sort_bis(tab_a, tab_b, tab_sort, &data);
		data.a++;
	}
}
