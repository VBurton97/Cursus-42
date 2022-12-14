/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:37:06 by vburton           #+#    #+#             */
/*   Updated: 2023/01/11 18:58:58 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	int		numbers_left_in_chunk;
	int		chunk;
	int		count_reverse;
	int		y;
	int		number_of_chunk;
	int		pivot;
	float	pivot_sup;
}				t_data;

typedef struct s_tab
{
	char	colonne;
	int		size;
	int		pos_last_num;
	long	*tab;
	long	*tabtmp;

}				t_tab;

int		ft_is_bigger(t_tab *tab);
int		ft_find_next(t_tab *tab, int pivot);
int		ft_seek_smallest(t_tab *tab);
int		ft_check_input(int argc, char **argv, t_tab *tab);
char 	**ft_argv(int	argc, char **argv);
void	ft_init_tab(t_tab *tab_a, t_tab *tab_b, \
										int size, char **argv);
void	ft_sort_tab(t_tab *tabtmp, long *tab);
void	ft_swap(t_tab *tab, int r);
void	ft_swap_ss(t_tab *tab_a, t_tab *tab_b);
void	ft_rotate(t_tab *tab, int r);
void	ft_rotate_rr(t_tab *tab_a, t_tab *tab_b);
void	ft_reverse_rotate_rrr(t_tab *tab_a, t_tab *tab_b);
void	ft_reverse_rotate(t_tab *tab, int r);
void	ft_push_b(t_tab *tab_a, t_tab *tab_b);
void	ft_push_a(t_tab *tab_a, t_tab *tab_b);
void	ft_display(t_tab *tab_a, t_tab *tab_b);
void	ft_first_sort(t_tab *tab_a, t_tab *tab_b, long *tab_sort);
void	ft_second_sort(t_tab *tab_a, t_tab *tab_b);
void	ft_free(t_tab *tab_a, t_tab *tab_b, char **argv);

#endif
