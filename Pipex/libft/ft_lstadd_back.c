/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:37:38 by vburton           #+#    #+#             */
/*   Updated: 2023/01/10 15:23:01 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new_lst;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new_lst;
	}
}
