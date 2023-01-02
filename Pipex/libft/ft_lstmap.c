/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:54:57 by vburton           #+#    #+#             */
/*   Updated: 2022/11/16 20:57:52 by victor           ###   ########.fr       */
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
		ft_lstclear(&res, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		sec = ft_lstnew(f(lst->content));
		if (!sec)
		{
			ft_lstclear(&res, del);
			break ;
		}
		ft_lstadd_back(&res, sec);
		lst = lst->next;
	}
	return (res);
}
