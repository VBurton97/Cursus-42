/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:24:55 by victor            #+#    #+#             */
/*   Updated: 2023/01/11 19:38:59 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



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

void	ft_sort_tab(t_tab *tabtmp, long *tab)
{
	int		i;
	int		s;

	i = 0;
	while (i <= tabtmp->pos_last_num)
	{
		s = ft_seek_smallest(tabtmp);
		tab[i] = tabtmp->tabtmp[s];
		tabtmp->tabtmp[s] = 2147483647;
		i++;
	}
}

int	ft_seek_smallest(t_tab *tab)
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

char **ft_argv(int	argc, char **argv)
{
	int		i;
	char	**argvB;

	i = 0;
	if (argc == 2)
	{
		argvB = ft_split(argv[1], ' ');
		if (!argvB)
			return(NULL);
	}
	else
	{
		argvB = malloc(sizeof(char *) * (argc));
		if (!argvB)
			return(NULL);
		while (i < argc - 1)
		{
			argvB[i] = argv[i + 1];
			i++;
		}
		argvB[i] = NULL;
	}
	return (argvB);
}

void	ft_init_tab(t_tab *tab_a, t_tab *tab_b, int size, char **argv)
{
	int	i;

	i = 0;
	tab_a->colonne = 'a';
	tab_b->colonne = 'b';
	tab_a->size = size;
	tab_a->pos_last_num = size - 1;
	tab_b->size = size;
	tab_b->pos_last_num = -1;
	while (i < size)
	{
		tab_a->tab[i] = ft_atoi(argv[i]);
		tab_a->tabtmp[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab_b->tab[i] = 0;
		i++;
	}
}
