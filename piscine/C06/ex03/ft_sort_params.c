/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:43:38 by vburton           #+#    #+#             */
/*   Updated: 2022/09/13 13:55:59 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	swap(char **arga, char	**argb)
{
	char	*buffer;

	buffer = *arga;
	*arga = *argb;
	*argb = buffer;
}

void	sort(char **arga, int i)
{
	int	j;
	int	d;

	j = 0;
	d = ft_strlen(*arga);
	while (j < d)
	{
		if (arga[i][j] > arga[i + 1][j])
		{
			swap(&arga[i], &arga[i + 1]);
			break ;
		}
		if (arga[i][j] < arga[i + 1][j])
		{
			break ;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j < argc)
	{
		i = 1;
		while (i < argc - 1)
		{
			sort(argv, i);
			i++;
		}
		j++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
