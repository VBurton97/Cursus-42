/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pusch_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:44:41 by vburton           #+#    #+#             */
/*   Updated: 2022/12/06 14:03:01 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_pusch_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*ptr;

	new = ft_create_elem(data);
	ptr = ft_list_last(*begin_list);
	if (ptr == *begin_list)
		begin_list = new;
	else
		ptr->next = new;
}
