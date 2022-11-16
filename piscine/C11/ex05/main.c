/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:58:23 by vburton           #+#    #+#             */
/*   Updated: 2022/09/22 16:29:39 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

void	execution(char **argv, t_fcts *fcts, int i)
{
	int	a;
	int	b;
	int	res;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	res = 0;
	{
		if (i == 2 && b == 0)
			ft_putstr(ERROR_DIVIDE);
		else if (i == 4 && b == 0)
			ft_putstr(ERROR_MODULO);
		else
		{
			res = fcts[i].fct(a, b);
			ft_putnbr(res);
			ft_putstr("\n");
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_fcts	fcts[5];

	i = 0;
	tab_operand(fcts);
	if (argc == 4)
	{
		while (ft_strcmp(argv[2], fcts[i].operand) != 0 && i < 5)
		i++;
		if (i < 5)
			execution(argv, fcts, i);
		else
		{
			ft_putstr("0");
			ft_putstr("\n");
		}
	}
	return (0);
}
