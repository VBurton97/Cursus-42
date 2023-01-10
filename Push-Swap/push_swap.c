/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:00 by vburton           #+#    #+#             */
/*   Updated: 2023/01/10 17:54:25 by vburton          ###   ########.fr       */
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

void	ft_all(t_tab *tab_a, t_tab *tab_b, t_tab *tabtmp)
{
	long	*tab_sort;
	int		t;

	t = tab_a->size % 10;
	tab_sort = malloc(sizeof(long) * tab_a->size);
	if (!tab_sort)
		return ;
	ft_sort_tab(tabtmp, tab_sort);
	ft_first_sort(tab_a, tab_b, tab_sort);
	while (t != 0)
	{
		ft_push_b(tab_a, tab_b);
		t--;
	}
	ft_second_sort(tab_a, tab_b);
	free(tab_sort);
}

int	main(int argc, char **argv)
{
	t_tab	tab_a;
	t_tab	tab_b;
	t_tab	tabtmp;
	int		t;
	int	i;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[i])
		{
			ft_printf("%s\n", argv[i]);
			i++;
		}
		argc = i;
		ft_printf("argc = %d\n", argc);
	}
	// else
	// {
	// 	while (i < argc)
	// 	{
	// 		argv[i] = argv[i + 1];
	// 		i++;
	// 	}
	// }
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
	t = ft_check_input(argc, argv, &tab_a);
	if (t == 0)
		return (ft_printf("Error\n"), 0);
	if (argc == 4)
		ft_three(&tab_a);
	else if (argc == 6)
		ft_five(&tab_a, &tab_b);
	else
		ft_all(&tab_a, &tab_b, &tabtmp);
	return (0);
}
