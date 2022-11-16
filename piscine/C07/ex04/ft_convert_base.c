/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:51:36 by vburton           #+#    #+#             */
/*   Updated: 2022/09/16 12:50:04 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_itoa_base(int nbr, char *base);

int	is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || (base[i] >= 9 && base[i] <= 13) || \
					base[i] == 32 || base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_atoi(char *nbr, char *base)
{
	int	nb;
	int	i;
	int	sign;
	int	t_base;

	nb = 0;
	i = 0;
	sign = 1;
	t_base = ft_strlen(base);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
	{
		i++;
	}
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (is_in_base(nbr[i], base) < t_base)
	{
		nb = nb * t_base + is_in_base(nbr[i], base);
		i++;
	}
	return (nb * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		j;
	int		decimal;
	char	*res;

	i = 0;
	j = 0;
	decimal = 0;
	res = 0;
	if (is_base(base_from) == 1 && is_base(base_to) == 1)
	{
		decimal = my_atoi(nbr, base_from);
		res = ft_itoa_base(decimal, base_to);
	}
	return (res);
}
