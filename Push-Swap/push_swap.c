/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:00 by vburton           #+#    #+#             */
/*   Updated: 2022/12/08 19:01:17 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_tab(t_tab *tab_a, t_tab *tab_b, int size, char **argv)
{
	int	i;

	i = 0;
	tab_a->colonne = 'a';
	tab_b->colonne = 'b';
	tab_a->size = size;
	tab_a->pos_last_num = size - 1;
	tab_b->size = size;
	tab_b->pos_last_num = 0;
	while (i < size)
	{
		tab_a->tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab_b->tab[i - 1] = 0;
		i++;
	}
}

void	ft_display(t_tab *tab_a, t_tab *tab_b)
{
	int	i;

	i = 0;
	while (i < tab_a->size - 1)
	{
		printf("%d    %d\n", tab_a->tab[i], tab_b->tab[i]);
		i++;
	}
	printf("------\nA    B\n");
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
	while (i < tab->pos_last_num)
	{
		printf("tab->tab[i] = %d et tab->tab[smallest]= %d\n", tab->tab[i], tab->tab[smallest]);
		if (tab->tab[i] < tab->tab[smallest])
		{
			printf("i = %d\n", i);
			smallest = i;
		}
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

void	ft_all(t_tab *tab_a, t_tab *tab_b)
{
	int	i;
	int	s;

	i = 0;
	while (i < tab_a->size)
	{
		s = ft_seek_smalest(tab_a);
		printf("s = %d\n", s);
		while (s-- > 0)
			ft_rotate(tab_a);
		ft_push_b(tab_a, tab_b);
		i++;
	}
	//ft_display(tab_a, tab_b);
	while (i > 0)
	{
		ft_push_a(tab_a, tab_b);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab_a;
	t_tab	tab_b;

	i = 1;
	tab_a.tab = malloc(sizeof(int) * (argc - 1));
	if (!tab_a.tab)
		return (0);
	tab_b.tab = malloc(sizeof(int *) * (argc - 1));
	if (!tab_b.tab)
		return (free(tab_a.tab), tab_a.tab = 0, 0);
	ft_init_tab(&tab_a, &tab_b, argc, argv);
	ft_all(&tab_a, &tab_b);
	ft_display(&tab_a, &tab_b);
}
