/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:57:53 by vburton           #+#    #+#             */
/*   Updated: 2022/09/13 20:02:41 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	is_base(char *str)
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
				if (str[i] == str[j] || str[i] == '-' || str[i] == '+' \
						|| (str[i] >= 9 && str[i] <= 13) || str[i] == 32)
					return (0);
				j++;
			}
		i++;
		}
	}
	return (1);
}

int	convert(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	return (i);
}

int	my_atoi(char *str, char *base, int i, int nb)
{
	int	neg;

	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (!(convert(str[i], base) == (ft_len(base))))
	{
		nb = nb * ft_len(base) + convert(str[i], base);
		i++;
	}
	if (neg % 2 == 1)
		nb = (nb * -1);
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (is_base(base) == 1 && base[1])
	{
		nb = my_atoi(str, base, i, nb);
		return (nb);
	}
	return (0);
}
