/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:43:00 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/20 18:38:14 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "read.h"

char	**read_map(char *pwd_map)
{	
	char	*map;
	char	**tab_map;

	map = open_map(pwd_map);
	if (map)
	{	
		tab_map = ft_split(map, "\n");
		free(map);
		return (tab_map);
	}
	ft_putstr(ERR_MAP);
	return (NULL);
}

char	*open_map(char *pwd_map)
{
	int		file;
	char	*map;
	char	stamp[100000];
	int		size;

	file = open(pwd_map, O_RDONLY);
	if (file < 0)
		return (NULL);
	size = 0;
	while (read(file, &stamp[size], 1))
	{
		if (size + 1 >= 100000)
			return (NULL);
		size++;
	}
	map = ft_strdup(stamp);
	if (close(file) == -1)
	{
		free(map);
		return (NULL);
	}	
	return (map);
}
