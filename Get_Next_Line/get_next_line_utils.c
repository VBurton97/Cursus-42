/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:11:50 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 18:39:52 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\n');
		i++;
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}


size_t	ft_count(t_list *list)
{
	size_t	i;
	size_t	len;


	i = ft_lstsize(list);
	list = ft_lstlast(list);
	len = i * BUFF_SIZE + ft_strlen(list->content);
	return (len);
}

char	*ft_line(t_list **list)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = ft_count(list);
	line = malloc(sizeof(char) * (len + 1);
	if (!line)
		return (NULL);
	while (list)
	{

	}
}
