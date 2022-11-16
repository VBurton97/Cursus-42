/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:59:34 by vburton           #+#    #+#             */
/*   Updated: 2022/09/16 23:16:38 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str);

int	t_final(int nbr, char *base)
{
	int	i;
	int	t_base;

	i = 1;
	t_base = ft_strlen(base);
	while (nbr >= t_base)
	{
		i++;
		nbr = nbr / t_base;
	}
	if (nbr < 0)
		return (i + 1);
	return (i);
}

void	dest(int nbr, char *res, char *base)
{
	int	i;
	int	nb;
	int	t_base;
	int	buffer;

	i = 0;
	nb = nbr;
	t_base = ft_strlen(base);
	if (nb == 0)
		res[i++] = base[0];
	while (nb != 0)
	{
		buffer = nb % t_base;
		if (buffer < 0)
			buffer = buffer * -1;
		res[i] = base[buffer];
		i++;
		nb = nb / t_base;
	}
	if (nbr < 0)
	{
		res[i] = '-';
		i++;
	}
	res[i] = '\0';
}

void	invert(char *tab)
{
	int		i;
	char	buffer;
	int		t_tab;
	int		invers;

	i = 0;
	t_tab = ft_strlen(tab);
	invers = t_tab - 1;
	while (i < (t_tab / 2))
	{
		buffer = tab[i];
		tab[i] = tab[invers];
		tab[invers] = buffer;
		i++;
		invers--;
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		i;
	char	*res;
	int		t_res;

	i = 0;
	t_res = t_final(nbr, base);
	if (nbr < 0)
		t_res++;
	res = malloc(sizeof(char) * t_res);
	if (res == 0)
		return (0);
	dest(nbr, res, base);
	invert(res);
	return (res);
}
