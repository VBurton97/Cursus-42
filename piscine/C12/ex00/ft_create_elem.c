/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:53:33 by vburton           #+#    #+#             */
/*   Updated: 2022/12/06 13:03:25 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if(!lst)
		return (NULL);
	lst->next = NULL;
	lst->data = data;
	return (lst);
}
