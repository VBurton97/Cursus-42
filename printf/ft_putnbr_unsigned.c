/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:03:51 by vburton           #+#    #+#             */
/*   Updated: 2022/11/17 12:19:36 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr(unsigned int n, int len)
{
	if (n < 10 && n >= 0)
	{
		n = n + 48;
		ft_putchar(n);
	}
	else
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	return (1 + )
}
