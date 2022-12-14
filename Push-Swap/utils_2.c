/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:50:34 by vburton           #+#    #+#             */
/*   Updated: 2023/01/11 19:21:32 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_tab *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->pos_last_num)
	{
		j = i + 1;
		while (j <= tab->pos_last_num)
		{
			if (tab->tab[i] == tab->tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] > '9' || argv[i][j] < '0') && (argv[i][j] != '-' && argv[i][j] != '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_extrem(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((long)ft_atoi(argv[i]) != ft_atol(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_input(int argc, char **argv, t_tab *tab)
{
	if (argc < 1)
		return (0);
	if (check_duplicate(tab) == 0 || check_number(argv) == 0 || check_extrem(argv) == 0)
		return (0);
	return (1);
}

void	ft_free(t_tab *tab_a, t_tab *tab_b, char **argvB)
{
	free(argvB);
	free(tab_a->tab);
	free(tab_a->tabtmp);
	free(tab_b->tab);
}
