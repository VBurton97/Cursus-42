/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:31:30 by vburton           #+#    #+#             */
/*   Updated: 2022/11/21 09:05:22 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int len)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		len += 11;
	}
	if (n > INT_MIN && n <= INT_MAX)
	{
		if (n < 10 && n >= 0)
		{
			n = n + 48;
			ft_putchar(n);
		}
		else if (n < 0)
		{
			ft_putchar('-');
			len = ft_putnbr(n * -1, len);
		}
		else
		{
			len = ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
		len++;
	}
	return (len);
}
