/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:00 by vburton           #+#    #+#             */
/*   Updated: 2022/12/07 18:26:09 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_tab(t_tab *tab_a, t_tab *tab_b, int size, char **argv)
{
	int	i;

	i = 0;
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
			ft_rotate(tab);
		else
		{
		ft_rotate(tab);
		ft_rotate(tab);
		}
	}
	else
	{
		if (tab->tab[1] > tab->tab[2])
		{
			ft_rotate(tab);
			ft_swap(tab);
		}

	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_tab	tab_a;
	t_tab	tab_b;

	i = 1;
	tab_a.tab = malloc(sizeof(int) * (argc - 1));
	if(!tab_a.tab)
		return (0);
	tab_b.tab = malloc(sizeof(int *) * (argc - 1));
	if(!tab_b.tab)
		return(free(tab_a.tab),tab_a.tab = 0, 0);
	ft_init_tab(&tab_a, &tab_b, argc, argv);
	ft_three(&tab_a);
	ft_display(&tab_a, &tab_b);
}
