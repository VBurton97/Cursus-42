/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:49 by vburton           #+#    #+#             */
/*   Updated: 2022/11/23 18:25:16 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_next_keep(char *keep)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	if(!keep)
	{
		free(keep);
		return (NULL);
	}
	while (keep[i] != '\0')
		i++;
	next = ft_calloc((ft_strlen(keep) - i + 1), 1);
	while(keep[i])
		next[j++] = keep[i++];
	free(keep);
	return (next);
}

char	*ft_nl(char	*keep)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!keep)
		return (NULL);
	while (keep[i] != '\0' && keep[i])
		i++;
	res = ft_calloc(i + 2, 1);
	i = 0;
	while(keep[i])
	{
		res[i] = keep[i];
		i++;
	}
	return (res);
}

char	*ft_add_str(char	*keep, char	*buffer)
{
	char	*tmp;

	tmp = ft_strjoin(keep, buffer);
	if (!tmp)
		free(buffer);
	free(keep);
	return (tmp);
}

char	*seek(int fd, char *keep)
{
	int		r;
	char	*buffer;

	r = 1;
	if (!keep)
		keep = ft_calloc(1,1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			free(keep);
			return (NULL);
		}
		keep = ft_add_str(keep, buffer);
		if (ft_strchr(keep, '\n'))
			break;
	}
	free(buffer);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*keep;

	keep = seek(fd, keep);
	if (!keep)
		return (NULL);
	next_line = ft_nl(keep);
	keep = ft_next_keep(keep);
	return(next_line);
}

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

