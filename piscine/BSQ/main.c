/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:49:27 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/20 15:57:54 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"
#include "./includes/algo.h"
#include "./includes/read.h"
#include "./includes/srcs.h"

int	main(int argc, char **argv)
{
	char	**tab_map;
	int		i;

	if (argc == 1)
		blackspot();
	else
	{
		i = 1;
		while (i < argc)
		{
			tab_map = read_map(argv[i]);
			quest_accepted(tab_map);
			i++;
		}
	}
	return (0);
}

void	blackspot(void)
{
	char	**tab_map;
	char	buf[100000];
	char	*map;
	int		size;

	size = 0;
	while (read(0, &buf[size], 1))
	{
		if (size + 1 >= 100000)
		{
			ft_putstr(ERR_MAP);
			return ;
		}
		size++;
	}
	buf[size] = 0;
	map = ft_strdup(buf);
	tab_map = ft_split(map, "\n");
	free(map);
	quest_accepted(tab_map);
	return ;
}

void	quest_accepted(char **tab_map)
{
	if (tab_map)
	{
		if (is_valid_map(tab_map))
		{	
			sailing_to_treasure(tab_map);
			headache(tab_map);
			free_tab(tab_map);
			free(tab_map);
		}
		else
		{
			ft_putstr(ERR_MAP);
			free_tab(tab_map);
			free(tab_map);
		}
	}	
}

void	headache(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		ft_putstr(tab_map[i]);
		ft_putstr("\n");
		i++;
	}
	return ;
}
