/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:39:13 by vburton           #+#    #+#             */
/*   Updated: 2023/01/11 18:16:20 by victor           ###   ########.fr       */
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

void	ft_second_sort(t_tab *tab_a, t_tab *tab_b)
{
	int	a;

	while (tab_b->pos_last_num >= 0)
	{
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

void	ft_first_sort_last_if(t_tab *tab_a, t_tab *tab_b, \
							long *tab_sort, t_data *data)
{
	if (data->chunk == 1 && tab_b->tab[0] > data->pivot)
		data->y = 0;
	while (data->y >= 0)
	{
		if (tab_a->tab[0] > tab_sort[(tab_a->size / \
			(2 * data->number_of_chunk)) * (2 * data->chunk + 1) - 1])
			ft_rotate_rr(tab_a, tab_b);
		else
			ft_rotate(tab_b, 1);
		data->y--;
	}
}

void	ft_first_sort_bis(t_tab *tab_a, t_tab *tab_b, \
							long *tab_sort, t_data *data)
{
	while (data->numbers_left_in_chunk > 0)
	{
		if (tab_a->tab[0] <= data->pivot)
		{
			ft_push_b(tab_a, tab_b);
			data->numbers_left_in_chunk--;
		}
		else if (tab_a->tab[0] > data->pivot && tab_a->tab[0] < data->pivot_sup)
		{
			ft_push_b(tab_a, tab_b);
			data->y++;
			data->count_reverse++;
		}
		else if (tab_a->tab[0] > data->pivot)
			ft_rotate(tab_a, 1);
		else if (tab_a->tab[0] >= data->pivot && tab_b->tab[0] > \
					data->pivot && tab_b->tab[0] < data->pivot_sup)
			ft_rotate_rr(tab_a, tab_b);
		if (tab_a->tab[ft_find_next(tab_a, data->pivot_sup)] <= data->pivot)
		{
			ft_first_sort_last_if(tab_a, tab_b, tab_sort, data);
		}
	}
}

void	ft_first_sort(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
{
	t_data	data;

	data.chunk = 1;
	data.count_reverse = 0;
	data.y = 0;
	if (tab_a->size == 100)
		data.number_of_chunk = 5;
	else
		data.number_of_chunk = 10;
	while (data.chunk <= data.number_of_chunk)
	{
		data.pivot = tab_sort[tab_a->size / data.number_of_chunk * \
													data.chunk - 1];
		data.pivot_sup = tab_sort[(tab_a->size / \
			(2 * data.number_of_chunk)) * (2 * data.chunk + 1) - 1];
		data.numbers_left_in_chunk = tab_a->size / \
		data.number_of_chunk - data.count_reverse;
		while (data.count_reverse > 0)
		{
			ft_reverse_rotate(tab_b, 1);
			data.count_reverse--;
		}
		ft_first_sort_bis(tab_a, tab_b, tab_sort, &data);
		data.chunk++;
	}
}
