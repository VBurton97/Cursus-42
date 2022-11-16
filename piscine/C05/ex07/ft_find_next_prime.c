/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:55:38 by vburton           #+#    #+#             */
/*   Updated: 2022/09/12 19:30:38 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
int	ft_find_next_prime(int nb)
{
	int	i;
	int	count;

	i = 2;
	if (nb < 2)
		return (2);
	while (1)
	{
		count = 0;
		while (i < 46341 && i < nb)
		{
			if (nb % i == 0)
				count++;
			i++;
		}
		if (count == 0)
			return (nb);
		i = 2;
		nb++;
	}
}
