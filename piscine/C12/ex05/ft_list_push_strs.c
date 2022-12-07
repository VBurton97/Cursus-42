/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:04:07 by vburton           #+#    #+#             */
/*   Updated: 2022/12/06 15:29:05 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*lst;
	t_list	*new;

	i = 0;
	new = NULL;
	while(i < size)
	{
		lst = ft_create_elem(*strs[i]);
		if (!lst)
			return (new);
		lst->next = new;
		new = lst;
		i++;
	}
}
