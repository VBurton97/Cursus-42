/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:04 by vburton           #+#    #+#             */
/*   Updated: 2022/09/20 13:15:55 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "read.h"

int	check_first_line(char *tab)
{
	int	i;
	int	j;
	int	t;

	t = ft_strlen(tab);
	i = t - 1;
	while (i > t - 3)
	{
		j = i - 1;
		if (tab[i] == tab[j] || tab[i] < 32 || tab[j] < 32 || \
				tab[i] == 127 || tab[j] == 127)
			return (0);
		i--;
	}
	return (1);
}

int	check_tab(char **tab, char empty, char obstacle)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = ft_strlen(tab[1]);
	while (tab[i])
	{
		j = 0;
		while (j < len)
		{
			if (tab[i][j] != empty && tab[i][j] != obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_len_line(char **tab)
{
	int	i;
	int	len1;
	int	len_test;

	i = 1;
	len1 = ft_strlen(tab[1]);
	len_test = 0;
	if (len1 == 0)
		return (0);
	while (tab[i])
	{
		len_test = ft_strlen(tab[i]);
		if (len_test != len1)
			return (0);
		i++;
	}
	return (1);
}

int	check_numb_line(char **tab)
{
	int	first_size;
	int	size_tab;
	int	real_size_tab;

	first_size = ft_strlen(tab[0]) - 3;
	size_tab = height(tab);
	real_size_tab = ft_atoi(tab[0], first_size);
	if (size_tab != real_size_tab)
		return (0);
	return (1);
}

int	is_valid_map(char **tab)
{
	int		x;
	int		t;
	char	*empty;
	char	*obstacle;

	x = 0;
	t = ft_strlen(tab[0]);
	if (! (tab[1]))
		return (0);
	empty = &tab[0][t - 3];
	obstacle = &tab[0][t - 2];
	x += check_numb_line(tab);
	x += check_len_line(tab);
	x += check_first_line(tab[0]);
	x += check_tab(tab, *empty, *obstacle);
	if (x == 4)
		return (1);
	return (0);
}
