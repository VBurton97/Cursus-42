/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:00 by vburton           #+#    #+#             */
/*   Updated: 2022/12/19 22:20:19 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_display(t_tab *tab_a, t_tab *tab_b)
{
	int	i;

	i = 0;
	while (i < tab_a->size)
	{
		ft_printf("%d    %d\n", tab_a->tab[i], tab_b->tab[i]);
		i++;
	}
	ft_printf("------\nA    B\n");
}

void	ft_three(t_tab *tab)
{
	if (tab->tab[0] > tab->tab[1])
	{
		if (tab->tab[1] < tab->tab[2])
		{
			if (tab->tab[0] > tab->tab[2])
				ft_rotate(tab, 1);
			else
				ft_swap(tab, 1);
		}
		else
		{
			ft_swap(tab, 1);
			ft_reverse_rotate(tab, 1);
		}
	}
	else if (tab->tab[1] > tab->tab[2])
	{
		if (tab->tab[0] > tab->tab[2])
			ft_reverse_rotate(tab, 1);
		else if (tab->tab[0] < tab->tab[2])
		{
			ft_reverse_rotate(tab, 1);
			ft_swap(tab, 1);
		}
	}
}

int	ft_seek_smalest(t_tab *tab)
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

void	ft_five(t_tab *tab_a, t_tab *tab_b)
{
	int	i;
	int	s;

	i = 0;
	while (i < 2)
	{
		s = ft_seek_smalest(tab_a);
		if (s > 2)
		{
			while (s-- > 0)
				ft_rotate(tab_a, 1);
		}
		else if (s == 4)
			ft_reverse_rotate(tab_a, 1);
		else if (s == 3)
		{
			ft_reverse_rotate(tab_a, 1);
			ft_reverse_rotate(tab_a, 1);
		}
		ft_push_b(tab_a, tab_b);
		i++;
	}
	ft_three(tab_a);
	ft_push_a(tab_a, tab_b);
	ft_push_a(tab_a, tab_b);
}

void	ft_sort_tab(t_tab *tabtmp, long *tab)
{
	int		i;
	int		s;

	i = 0;
	while (i <= tabtmp->pos_last_num)
	{
		s = ft_seek_smalest(tabtmp);
		tab[i] = tabtmp->tab[s];
		tabtmp->tab[s] = 2147483649;
		i++;
	}
}

void	ft_second_sort(t_tab *tab_a, t_tab *tab_b)
{
	int	a;
	int	b;
	int	i;
	int	j;
	int	y;
	int	pos;

	b = tab_b->pos_last_num / 2;
	if (tab_a->tab[0] > tab_a->tab[1])
		ft_swap(tab_a, 1);
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
				ft_reverse_rotate(tab_b, 1);
				i++;
			}
		}
		else
		{
			while (pos > 0)
			{
				ft_rotate(tab_b, 1);
				pos--;
			}
		}
		ft_push_a(tab_a, tab_b);
	}
}

void	ft_first_sort(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
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
				s--;
			}
			else if (tab_a->tab[tab_a->pos_last_num] < median)
			{
				ft_reverse_rotate(tab_a, 1);
				ft_push_b(tab_a, tab_b);
				s--;
			}
			else
				ft_rotate(tab_a, 1);
		}
	}
}

void	ft_all(t_tab *tab_a, t_tab *tab_b, t_tab *tabtmp)
{
	long	*tab_sort;

	tab_sort = malloc(sizeof(long) * tab_a->size);
	if (!tab_sort)
		return ;
	ft_sort_tab(tabtmp, tab_sort);
	ft_first_sort_bis(tab_a, tab_b, tab_sort);
	// ft_second_sort_bis(tab_a, tab_b);
	ft_second_sort_bis_bis(tab_a, tab_b, tab_sort);
}

int	main(int argc, char **argv)
{
	t_tab	tab_a;
	t_tab	tab_b;
	t_tab	tabtmp;

	tab_a.tab = malloc(sizeof(long) * (argc - 1));
	if (!tab_a.tab)
		return (0);
	tab_b.tab = malloc(sizeof(long) * (argc - 1));
	if (!tab_b.tab)
		return (free(tab_a.tab), tab_a.tab = 0, 0);
	tabtmp.tab = malloc(sizeof(long) * (argc - 1));
	if (!tab_b.tab)
		return (free(tab_a.tab), free(tab_b.tab), 0);
	ft_init_tab(&tab_a, &tab_b, &tabtmp, argc - 1, argv);
	// ft_push_b(&tab_a, &tab_b);
	// ft_display(&tab_a, &tab_b);
	ft_all(&tab_a, &tab_b, &tabtmp);
	// ft_push_b(&tab_a, &tab_b);
	// ft_push_b(&tab_a, &tab_b);
	// ft_rotate_rr(&tab_a, &tab_b);
	// ft_push_b(&tab_a, &tab_b);
	// ft_rotate(&tab_b);
	//printf("poslatnum = %d\n", tab_b.pos_last_num);
	// ft_display(&tab_a, &tab_b);
	// ft_printf("pos_last_num = %d\n", tab_a.pos_last_num);
	return (0);
}
