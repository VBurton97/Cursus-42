/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:31:30 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 15:19:11 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base, int len)
{
	if (nbr < 16 && nbr >= 0)
		write(1, &base[nbr], 1);
	else
	{
		len = ft_putnbr_base(nbr / 16, base, len);
		ft_putnbr_base(nbr % 16, base, len);
	}
	return (++len);
}
