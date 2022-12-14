/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:37:06 by vburton           #+#    #+#             */
/*   Updated: 2022/12/14 15:50:21 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_tab
{
	char	colonne;
	int		size;
	int		pos_last_num;
	long		*tab;

}				t_tab;

void	ft_swap(t_tab *tab);
void	ft_swap_ss(t_tab *tab_a, t_tab *tab_b);
void	ft_rotate(t_tab *tab);
void	ft_rotate_rr(t_tab *tab_a, t_tab *tab_b);
void	ft_reverse_rotate_rrr(t_tab *tab_a, t_tab *tab_b);
void	ft_reverse_rotate(t_tab *tab);
void	ft_push_b(t_tab *tab_a, t_tab *tab_b);
void	ft_push_a(t_tab *tab_a, t_tab *tab_b);
void	ft_display(t_tab *tab_a, t_tab *tab_b);

void	ft_first_sort_bis(t_tab *tab_a, t_tab *tab_b, long *tab_sort);
void	ft_second_sort_bis(t_tab *tab_a, t_tab *tab_b);

#endif
