/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:31:30 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 15:38:43 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(int n, int len)
{
	unsigned long int	nbis;

	nbis = (unsigned)n;
	if (nbis < 10)
	{
		nbis = nbis + 48;
		ft_putchar(nbis);
	}
	else
	{
		len = ft_putnbr(nbis / 10, len);
		ft_putnbr(nbis % 10, len);
	}
	return (++len);
}
