/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adresse_hexa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:47:04 by vburton           #+#    #+#             */
/*   Updated: 2022/11/30 16:04:51 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexa(unsigned long long nbr, char *base, int len)
{
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		len = ft_write_hexa(nbr / 16, base, len);
		ft_write_hexa(nbr % 16, base, len);
	}
	len++;
	return (len);
}

int	ft_putnbr_base_hexa(unsigned long long nbr, int len)
{
	write(1, "0x", 2);
	len += 2;
	len = ft_write_hexa(nbr, EXA_DOWN, len);
	return (len);
}
