/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:04 by vburton           #+#    #+#             */
/*   Updated: 2022/09/08 17:00:43 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb <= 2147483647 && nb > -2147483648)
	{
		if (nb >= 0 && nb < 10)
		{
			nb = nb + 48;
			write(1, &nb, 1);
		}
		else if (nb < 0)
		{
			write(1, "-", 1);
			ft_putnbr(nb * -1);
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}
