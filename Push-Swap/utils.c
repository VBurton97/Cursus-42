/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:24:55 by victor            #+#    #+#             */
/*   Updated: 2023/01/09 13:19:26 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_bigger(t_tab *tab)
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

int ft_find_next(t_tab *tab, int pivot)
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

void	ft_sort_tab(t_tab *tabtmp, long *tab)
{
	int		i;
	int		s;

	i = 0;
	while (i <= tabtmp->pos_last_num)
	{
		s = ft_seek_smallest(tabtmp);
		tab[i] = tabtmp->tab[s];
		tabtmp->tab[s] = 2147483649;
		i++;
	}
}

int ft_seek_smallest(t_tab *tab)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 0;
	while (i <= tab->pos_last_num)
	{
		if (tab->tab[i] < tab->tab[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

void	ft_init_tab(t_tab *tab_a, t_tab *tab_b, t_tab *tabtmp, int size, char **argv)
{
	int	i;

	i = 1;
	tab_a->colonne = 'a';
	tab_b->colonne = 'b';
	tab_a->size = size;
	tab_a->pos_last_num = size - 1;
	tab_b->size = size;
	tab_b->pos_last_num = -1;
	tabtmp->size = size;
	tabtmp->pos_last_num = size - 1;
	while (i <= size)
	{
		tab_a->tab[i - 1] = ft_atoi(argv[i]);
		tabtmp->tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 1;
	while (i <= size)
	{
		tab_b->tab[i - 1] = 0;
		i++;
	}
}
