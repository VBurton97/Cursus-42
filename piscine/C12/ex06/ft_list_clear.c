/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:29:57 by vburton           #+#    #+#             */
/*   Updated: 2022/12/06 15:40:09 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list			*cln;

	cln = begin_list;
	while (cln)
	{
		free_fct(begin_list->data);
		free_fct(begin_list->next);
		cln = cln->next;
	}
}
