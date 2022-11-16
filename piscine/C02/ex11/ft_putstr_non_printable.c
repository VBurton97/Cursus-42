/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:00:52 by vburton           #+#    #+#             */
/*   Updated: 2022/09/06 10:42:55 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	creation_tab(char *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		tab[i] = i + 48;
		i++;
	}
	while (i < 16)
	{
		tab[i] = i + 87;
		i++;
	}
}

void	conversion(int c, char *base)
{
	if (c > 16)
	{
		conversion(c / 16, base);
		conversion(c % 16, base);
	}
	write(1, &base[c], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	base16[255];

	i = 0;
	creation_tab(base16);
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			ft_putchar(str[i]);
		}
		else
		{
			write(1, "\\", 1);
			if (str[i] < 16)
			{	
				write(1, "0", 1);
				conversion(str[i], base16);
			}
			else
				conversion(str[i], base16);
		}
		i++;
	}
}
