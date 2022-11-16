/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:31:30 by vburton           #+#    #+#             */
/*   Updated: 2022/09/08 17:47:19 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	base_conforme(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0])
	{
		while (str[i])
		{
			j = i + 1;
			while (str[j])
			{
				if ((str[i] == str[j] && j != i) \
						|| str[j] == '+' || str[i] == '-')
				{
					return (0);
				}
				j++;
			}
		i++;
		}
	}
	return (1);
}

int	ft_strlen_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (i > 1)
		return (i);
	else
		return (0);
}

void	ft_write(int nbr, char *base, int t_base)
{		
	if (nbr < t_base && nbr >= 0)
		write(1, &base[nbr], 1);
	if (nbr < 0 && nbr > -t_base)
		write(1, &base[nbr * -1], 1);
	if (nbr >= t_base || nbr <= (t_base * -1))
	{
		ft_write(nbr / t_base, base, t_base);
		ft_write(nbr % t_base, base, t_base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	t_base;

	t_base = ft_strlen_base(base);
	if (base_conforme(base) == 1 && t_base > 1)
	{
		if (nbr < 0)
			write(1, "-", 1);
		ft_write(nbr, base, t_base);
	}
}
