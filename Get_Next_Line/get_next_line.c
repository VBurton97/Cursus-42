/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:49 by vburton           #+#    #+#             */
/*   Updated: 2022/11/21 20:53:36 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd)
{
	int	i;
	int	j;
	int	r;
	char	buffer[BUFFER_SIZE + 1];
	char	*cln;
	char	*clnbis;
	char	*next_line;

	i = 0;
	if (fd <= 0)
		return (NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	if (r == 0)
		return (NULL);
	buffer[r] = '\0';
	next_line = ft_strdup(buffer);
	while (1)
	{
		j = 0;
		if (r == BUFFER_SIZE)
		{
			r = read(fd, buffer, BUFFER_SIZE);
			buffer[r] = '\0';
		}
		while (buffer[j] && buffer[j] != '\n')
			j++;
		if (j < BUFFER_SIZE)
		{
			while (buffer[i] && buffer[i] != '\n')
				i++;
		printf("i = %d\n", i);
			cln = ft_substr(buffer, 0, i);
			clnbis = ft_strdup(next_line);
			free(next_line);
			next_line = ft_strjoin(clnbis, cln);
			free(cln);
			free(clnbis);
			break ;
		}
		else
		{
			cln = ft_strdup(buffer);
			clnbis = ft_strdup(next_line);
			free(next_line);
			next_line = ft_strjoin(clnbis, cln);
			free(cln);
			free(clnbis);
		}
	}
	return (next_line);
}


int	main(int argc, char **argv)
{
	int		fd;
	char	*test;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		test = get_next_line(fd);
		printf("Resultat : %s\n", test);
	}
}
