/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:17:55 by vburton           #+#    #+#             */
/*   Updated: 2022/09/03 10:16:36 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_comb(void)
{
	int	i;
	int	y;
	int	x;

	i = 48;
	while (i < 56)
	{
		y = i + 1;
		while (y < 58)
		{
			x = y + 1;
			while (x < 58)
			{		
				write(1, &i, 1);
				write(1, &y, 1);
				write(1, &x, 1);
				if (i != 55)
					write(1, ", ", 2);
				x++;
			}
			y++;
		}
		i++;
	}
}
