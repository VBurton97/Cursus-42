/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:49 by vburton           #+#    #+#             */
/*   Updated: 2022/11/23 17:33:33 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	check(char *tmp)
{
	int	i;

	if (!tmp)
		return (0);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_union(char *line, char *buffer)
{
	char	*cln;

	cln = ft_strdup(line);
	free(line);
	line = ft_strjoin(cln, buffer);
	free(cln);
	return (line);
}

char	*find_nl(int fd, char *tmp)
{
	char	*buffer;
	char	*line;
	int		r;
	int		i;

	i = 0;
	if (check(tmp))
		return (tmp);
	if (tmp == '\0')
		line = ft_calloc(1, 1);
	else
		line = tmp;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
			return (NULL);
		line = ft_union(line, buffer);
		while (line[i] != '\n' && line[i])
			i++;
		if (line[i] == '\n' || r < BUFFER_SIZE)
		{
			free(buffer);
			return (line);
		}
	}
}

char	*get_next_line(int fd)
{
	static int	i;
	static char	*tmp;
	char		*next_line;

	if (fd <= 0)
		return (NULL);
	i = 0;
	tmp = find_nl(fd, tmp);
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	next_line = ft_substr(tmp, 0, ++i);
	tmp = ft_substr(tmp, i++, BUFFER_SIZE);
	if (!tmp)
		free(tmp);
	return (next_line);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*test;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		test = get_next_line(fd);
		printf("Resultat : %s", test);
		test = get_next_line(fd);
		printf("Resultat : %s", test);

		test = get_next_line(fd);
		printf("Resultat : %s", test);
		test = get_next_line(fd);
		printf("Resultat : %s", test);
		test = get_next_line(fd);
		printf("Resultat : %s", test);
		test = get_next_line(fd);
		printf("Resultat : %s", test);

	}
}
*/
