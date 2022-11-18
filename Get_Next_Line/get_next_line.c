/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:28:14 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 18:36:04 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	i;
	size_t	j;
	t_list	**list;
	t_list	*new;
	char 	buf[BUFF_SIZE + 1];
	char	*line;

	j = 0;
	i = read(fd, buf, BUFF_SIZE);
	buf[i] = '\0';
	while (buf[j])
	{
		if (buf[j] && j == BUFF_SIZE && buf[j++] == '\0')
		{
			new->content = buf;
			ft_lstadd_back(list, new);
		}
		else if (buf[j] == '\n')
			line = ft_line(list);
	}

}
