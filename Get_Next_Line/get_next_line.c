/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:49 by vburton           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/28 19:05:42 by vburton          ###   ########.fr       */
=======
/*   Updated: 2022/11/29 10:59:19 by vburton          ###   ########.fr       */
>>>>>>> final_GNL
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_keep(char *keep)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	j = 0;
	if (!keep || keep[0] == '\0')
		return (free(keep), keep = NULL, NULL);
	while (keep[i] != '\n' && keep[i])
		i++;
	next = ft_calloc((ft_strlen(keep) - i + 1), 1);
	if (!next)
		return (free(keep), keep = NULL, NULL);
	if (i != ft_strlen(keep))
		i++;
	while (keep[i])
		next[j++] = keep[i++];
	return (free(keep), keep = NULL, next);
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
	if (keep[i] == '\n')
		i++;
	res = ft_calloc(i + 1, 1);
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
	return (free(keep), keep = NULL, tmp);
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
		return (free(keep), keep = NULL, NULL);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*keep;

	if (fd < 0 || read(fd, keep, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (keep)
			free(keep);
		keep = NULL;
		return (NULL);
	}
	keep = seek(fd, keep);
	if (!keep)
		return (free(keep), keep = NULL, NULL);
	next_line = ft_nl(keep);
	keep = ft_next_keep(keep);
	if (!next_line)
	{
		free(keep);
		keep = NULL;
	}
	return (next_line);
}
