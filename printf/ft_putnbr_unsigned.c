/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:31:30 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 12:35:33 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(int n, int len)
{
	unsigned long int	nbis;

	nbis = (unsigned)n;
	if (nbis < 10 && nbis >= 0)
	{
		nbis = nbis + 48;
		ft_putchar(nbis);
	}
	else if (nbis < 0)
	{
		ft_putchar('-');
		len = ft_putnbr(nbis * -1, len);
	}
	else
	{
		len = ft_putnbr(nbis / 10, len);
		ft_putnbr(nbis % 10, len);
	}
	len++;
	return (len);
}

