/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:49 by vburton           #+#    #+#             */
/*   Updated: 2022/11/25 18:09:23 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_next_keep(char *keep)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	j = 0;
	if (!keep || keep[0] == '\0')
	{
		free(keep);
		return (NULL);
	}
	while (keep[i] != '\n' && keep[i])
		i++;
	next = ft_calloc((ft_strlen(keep) - i + 1), 1);
	if (!next)
	{
		free(keep);
		return (NULL);
	}
	if (i != ft_strlen(keep))
		i++;
	while (keep[i])
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
	while (keep[i] != '\n' && keep[i])
		i++;
	res = ft_calloc(i + 2, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (keep[i])
	{
		res[i] = keep[i];
		if (keep[i] == '\n')
			break ;
		i++;
	}
	return (res);
}

char	*ft_add_str(char	*keep, char	*buffer, size_t r)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < r)
		i++;
	buffer[i] = '\0';
	tmp = ft_strjoin(keep, buffer);
	free(keep);
	return (tmp);
}

char	*seek(int fd, char *keep)
{
	size_t	r;
	char	buffer[BUFFER_SIZE + 1];

	r = 1;
	while (r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if ((int)r == -1)
			break ;
		keep = ft_add_str(keep, buffer, r);
		if (!keep)
			return (NULL);
		if (ft_strchr(keep, '\n'))
			break ;
	}
	if (r == 0 && keep[0] == '\0')
	{
		free(keep);
		return (NULL);
	}
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*keep[10240];

	if (fd < 0 || read(fd, keep, 0) || BUFFER_SIZE <= 0)
	{
		free(keep);
		keep[fd] = NULL;
		return (NULL);
	}
	keep[fd] = seek(fd, keep[fd]);
	if (!keep)
	{
		free(keep[fd]);
		keep[fd] = NULL;
		return (NULL);
	}
	next_line = ft_nl(keep[fd]);
	keep[fd] = ft_next_keep(keep[fd]);
	if (!next_line)
		free(keep[fd]);
	return (next_line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*test;

// 	if (argc > 1)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		test = get_next_line(fd);
// 		while (test != NULL)
// 		{
// 			printf("%s", test);
// 			free(test);
// 			test = get_next_line(fd);
// 		}
// 		close(fd);
// 		if(test)
// 			free(test);
// 	}
// }
