/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:54:57 by vburton           #+#    #+#             */
/*   Updated: 2022/11/15 10:05:42 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*sec;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		sec = ft_lstnew(f(lst->content));
		if (!sec)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&res, del);
			break ;
		}
		ft_lstadd_back(&res, sec);
		lst = lst->next;
	}
	return (res);
}
