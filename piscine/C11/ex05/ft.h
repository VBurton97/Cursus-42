/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:47:14 by vburton           #+#    #+#             */
/*   Updated: 2022/09/22 11:00:50 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef struct is_fcts
{
	char	*operand;
	int		(*fct)(int a, int b);
}t_fcts;

# define ERROR_DIVIDE "Stop : division by zero\n"
# define ERROR_MODULO "Stop : modulo by zero\n"

void		tab_operand(t_fcts *fcts);
int			ft_atoi(char *str);
void		ft_putnbr(int nb);
int			ft_strcmp(char *s1, char *s2);
int			plus(int a, int b);
int			minus(int a, int b);
int			divide(int a, int b);
int			multiply(int a, int b);
int			modulo(int a, int b);
void		ft_putstr(char *str);

#endif
