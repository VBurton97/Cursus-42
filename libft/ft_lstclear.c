/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:03:09 by vburton           #+#    #+#             */
/*   Updated: 2022/11/16 20:57:47 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cln;
	t_list	*next;

	if (!lst || !del)
		return ;
	cln = *lst;
	next = cln;
	while (cln)
	{
		next = cln;
		cln = cln->next;
		ft_lstdelone(next, del);
	}
	*lst = NULL;
}
