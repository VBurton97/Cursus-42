/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:28:14 by vburton           #+#    #+#             */
/*   Updated: 2022/11/21 13:07:19 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	size_t	i;
	size_t	j;
	t_list	**list;
	t_list	**cln;
	t_list	*new;
	char 	buf[BUFFER_SIZE + 1];
	char	*line;

	j = 0;
	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = '\0';
	list = NULL;
	cln = list;
	while (buf[j])
	{
		if (j == (BUFFER_SIZE - 1) && buf[BUFFER_SIZE - 1])
		{
			new = ft_lstnew(buf);
			new->next = NULL;
			ft_lstadd_back(list, new);
			dprintf(1, "liste : %s \n", (*list)->content);
			dprintf(1, "listebis : %s \n", (*cln)->content);
			read(fd, buf, BUFFER_SIZE);
			j = 0;
		}
		else if (buf[j] == '\n')
		{
			line = ft_line(cln);
			return (line);
		}
		j++;
	}
	return (line);
}


int	main(int argc, char **argv)
{
	int		fd;
	char	*test;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		test = get_next_line(fd);
		printf("Resultat : %s \n", test);
	}
}

