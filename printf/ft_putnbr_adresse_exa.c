/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adresse_exa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:47:04 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 15:09:24 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_exa(unsigned long long nbr, char *base, int len)
{
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		len = ft_write_exa(nbr / 16, base, len);
		ft_write_exa(nbr % 16, base, len);
	}
	len++;
	return (len);
}

int	ft_putnbr_base_exa(unsigned long long nbr, int len)
{
	write(1, "0x", 2);
	len = ft_write_exa(nbr, EXA_DOWN, len);
	len += 2;
	return (len);
}
