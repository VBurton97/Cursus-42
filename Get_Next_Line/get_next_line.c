/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:49 by vburton           #+#    #+#             */
/*   Updated: 2022/11/24 17:26:17 by vburton          ###   ########.fr       */
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
	char	*buffer;

	r = 1;
	if (!keep)
		keep = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	while (r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if ((int)r == -1)
			break ;
		keep = ft_add_str(keep, buffer, r);
		if (ft_strchr(keep, '\n'))
			break ;
	}
	free(buffer);
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
	static char	*keep;
	if (fd < 0 || read(fd, keep, 0) || BUFFER_SIZE <= 0)
	{
		free(keep);
		keep = NULL;
		return (NULL);
	}
	keep = seek(fd, keep);
	if (!keep)
		return (NULL);
	next_line = ft_nl(keep);
	keep = ft_next_keep(keep);

	return(next_line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*test;
// 	if (argc > 1)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		test = get_next_line(fd);
// 		printf("Resultat : %s", test);
// 		test = get_next_line(fd);
// 		printf("Resultat : %s", test);
// 		test = get_next_line(fd);
// 		printf("Resultat : %s", test);
// 		test = get_next_line(fd);
// 		printf("Resultat : %s", test);
// 		test = get_next_line(fd);
// 		printf("Resultat : %s", test);
// 		test = get_next_line(fd);
// 		printf("Resultat : %s", test);
// 	}
// }
