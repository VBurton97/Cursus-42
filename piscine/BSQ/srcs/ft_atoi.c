/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:47:49 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/20 18:39:06 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_atoi(char *str, int nbr)
{
	int				i;
	int				n;
	unsigned int	nb;
	int				sign;

	nb = 0;
	i = 0;
	sign = 1;
	n = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && ((str[i] == '-') || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && n < nbr)
	{
		nb = str[i] - 48 + (nb * 10);
		i++;
	}
	return (sign * nb);
}
