/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adresse_exa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:47:04 by vburton           #+#    #+#             */
/*   Updated: 2022/11/17 19:00:22 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_conforme_exa(char *str)
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

int	ft_strlen_base_exa(char *base)
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

int	ft_write_exa(unsigned long long nbr, char *base, unsigned long long t_base, int len)
{
	if (nbr < t_base && nbr >= 0)
		write(1, &base[nbr], 1);
	if (nbr >= t_base )
	{
		len = ft_write_exa(nbr / t_base, base, t_base, len);
		ft_write_exa(nbr % t_base, base, t_base, len);
	}
	len++;
	return (len);
}

int	ft_putnbr_base_exa(unsigned long long nbr, char *base, int len)
{
	unsigned long long	t_base;

	t_base = ft_strlen_base_exa(base);
	if (base_conforme_exa(base) == 1 && t_base > 1)
	{
		write(1, "0x", 2);
		len = ft_write_exa(nbr, base, t_base, len);
		len += 2;
	}
	return (len);
}
