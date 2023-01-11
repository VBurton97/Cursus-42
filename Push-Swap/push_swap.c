/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:00 by vburton           #+#    #+#             */
/*   Updated: 2023/01/11 19:39:49 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_five(t_tab *tab_a, t_tab *tab_b)
{
	int	i;
	int	s;
	int	smallest;

	i = 0;
	while (i < 2)
	{
		s = ft_seek_smallest(tab_a);
		smallest = tab_a->tab[s];
		if (s <= 2)
		{
			while (s-- > 0)
				ft_rotate(tab_a, 1);
		}
		else
		{
			while (tab_a->tab[0] != smallest)
				ft_reverse_rotate(tab_a, 1);
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
	long	*tab_sort;
	int		t;

	t = tab_a->size % 10;
	tab_sort = malloc(sizeof(long) * tab_a->size);
	if (!tab_sort)
		return (free(tab_a->tab), free(tab_b->tab), free(tab_a->tabtmp));
	ft_sort_tab(tab_a, tab_sort);
	ft_first_sort(tab_a, tab_b, tab_sort);
	while (t != 0)
	{
		ft_push_b(tab_a, tab_b);
		t--;
	}
	ft_second_sort(tab_a, tab_b);
	free(tab_sort);
}
int	ft_execute(int	argc, char **argv, t_tab *tab_a, t_tab *tab_b)
{
	int		t;
	
	tab_a->tab = malloc(sizeof(long) * (argc));
	if (!tab_a->tab)
		return (0);
	tab_b->tab = malloc(sizeof(long) * (argc));
	if (!tab_b->tab)
		return (free(tab_a->tab), 0);
	tab_a->tabtmp = malloc(sizeof(long) * (argc));
	if (!tab_b->tab)
		return (free(tab_a->tab), free(tab_b->tab), 0);
	ft_init_tab(tab_a, tab_b, argc, argv);
	t = ft_check_input(argc, argv, tab_a);
	if (t == 0)
		return (ft_printf("Error\n"), 0);
	if (argc == 3)
		ft_three(tab_a);
	else if (argc == 5)
		ft_five(tab_a, tab_b);
	else
		ft_all(tab_a, tab_b);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		m;
	char	**argvB;
	t_tab	tab_a;
	t_tab	tab_b;

	i = 0;
	argvB = ft_argv(argc, argv);
	if (!argvB)
		return (0);
	while (argvB[i])
			i++;
	argc = i;
	ft_execute(argc, argvB, &tab_a, &tab_b);
	ft_free(&tab_a, &tab_b, argvB);
	return (0);
}
