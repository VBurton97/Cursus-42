/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:00 by vburton           #+#    #+#             */
/*   Updated: 2022/12/13 13:52:36 by vburton          ###   ########.fr       */
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
				ft_rotate(tab);
			else
				ft_swap(tab);
		}
		else
		{
			ft_swap(tab);
			ft_reverse_rotate(tab);
		}
	}
	else if (tab->tab[1] > tab->tab[2])
	{
		if (tab->tab[0] > tab->tab[2])
			ft_reverse_rotate(tab);
		else if (tab->tab[0] < tab->tab[2])
		{
			ft_reverse_rotate(tab);
			ft_swap(tab);
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
				ft_rotate(tab_a);
		}
		else if (s == 4)
			ft_reverse_rotate(tab_a);
		else if (s == 3)
		{
			ft_reverse_rotate(tab_a);
			ft_reverse_rotate(tab_a);
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
	int	i;
	int	j;
	int	y;
	int	pos;

	if (tab_a->tab[0] > tab_a->tab[1])
		ft_swap(tab_a);
	while (tab_b->pos_last_num >= 0)
	{
		i = 0;
		j = tab_b->pos_last_num + 1;
		y = 0;
		//ft_printf("******** j = %d *********\n", j);
		pos = 0;
		while (y <= j)
		{
			if (tab_b->tab[y] > tab_b->tab[pos])
				pos = y;
			y++;;
		}
		//ft_printf("******** pos = %d *********\n", pos);
		//ft_display(tab_a, tab_b);
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
		a--;
	}
}

void	ft_first_sort(t_tab *tab_a, t_tab *tab_b, long *tab_sort)
{
	int	i;
	int	s;
	int	m;

	while (tab_a->pos_last_num > 1)
	{
		s = (tab_a->pos_last_num + 1)/ 2;
		m = tab_sort[tab_a->size - s];
		if (m == tab_sort[tab_a->size - 1])
			m--;
		while (0 < s)
		{
			if (tab_a->tab[0] < m)
			{
				ft_push_b(tab_a, tab_b);
				s--;
			}
			else if (tab_a->tab[tab_a->pos_last_num] < m)
			{
				ft_reverse_rotate(tab_a);
				ft_push_b(tab_a, tab_b);
				s--;
			}
			else
				ft_rotate(tab_a);
		}
	}
}

void	ft_all(t_tab *tab_a, t_tab *tab_b, t_tab *tabtmp)
{
	int	m;
	long	*tab_sort;

	tab_sort = malloc(sizeof(long) * tab_a->size);
	if (!tab_sort)
		return ;
	ft_sort_tab(tabtmp, tab_sort);
	int i = 0;
	ft_first_sort(tab_a, tab_b, tab_sort);
	ft_second_sort(tab_a, tab_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab_a;
	t_tab	tab_b;
	t_tab	tabtmp;

	i = 1;
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
	//ft_display(&tab_a, &tab_b);
	ft_all(&tab_a, &tab_b, &tabtmp);
	// ft_push_b(&tab_a, &tab_b);
	// ft_push_b(&tab_a, &tab_b);
	// ft_push_b(&tab_a, &tab_b);
	// ft_reverse_rotate(&tab_b);
	//ft_reverse_rotate(&tab_a);
	//printf("poslatnum = %d\n", tab_b.pos_last_num);
	//ft_display(&tab_a, &tab_b);
	return (0);
}
