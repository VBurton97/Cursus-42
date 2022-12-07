/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:35:55 by vburton           #+#    #+#             */
/*   Updated: 2022/12/07 14:36:05 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_tab *tab)
{
	int	cln;

	if (tab->size >= 1)
	{
		if (tab->tab[0] && tab->tab[1])
		{

			cln = tab->tab[0];
			tab->tab[0] = tab->tab[1];
			tab->tab[1] = cln;
		}
	}
}

void	ft_swap_ss(t_tab *tab_a, t_tab *tab_b)
{
	ft_swap(tab_a);
	ft_swap(tab_b);
}
