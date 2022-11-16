/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:03:09 by vburton           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:15 by vburton          ###   ########.fr       */
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
