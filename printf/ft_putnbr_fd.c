/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:31:30 by vburton           #+#    #+#             */
/*   Updated: 2022/11/16 20:13:53 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		i = 11;
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
			ft_putnbr(n * -1);
		}
		else
		{
			ft_putnbr_fd(n / 10);
			ft_putnbr_fd(n % 10);
		}
	}
}
