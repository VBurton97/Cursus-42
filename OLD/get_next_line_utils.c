/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:11:50 by vburton           #+#    #+#             */
/*   Updated: 2022/11/21 13:11:05 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp)
		{
			if(tmp->next == NULL)
			{
				tmp->next = new;
				return ;
			}
			tmp = tmp->next;
		}
	}
}


int	ft_lstsize(t_list **lst)
{
	int	i;

	i = 0;
	while (*lst)
	{
		*lst = (*lst)->next;
		i++;
	}
	return (i);
}


size_t	ft_count(t_list **list)
{
	size_t	i;
	size_t	len;

	i = ft_lstsize(list);
	*list = ft_lstlast(*list);
	len = i * BUFFER_SIZE + ft_strlen((*list)->content);
	return (len);
}

size_t	ft_strlcat(char *dest, \
	const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	if (dest == NULL && dstsize == 0)
		return (0);
	len_dest = ft_strlen((char *)dest);
	len_src = ft_strlen((char *)src);
	if (dstsize < len_dest || dstsize == 0)
		return (dstsize + len_src);
	while (src[i] != '\0' && i + len_dest < dstsize - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}


char	*ft_line(t_list **list)
{
	size_t	i;
	size_t	len;
	char	*line;

	dprintf(1, "%s\n", (*list)->content);
	i = 0;
	len = ft_count(list);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (list)
	{
		ft_strlcat(line, (*list)->content, BUFFER_SIZE + 1);
		(*list) = (*list)->next;
	}
	return (line);
}
