/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_len_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:13:29 by vburton           #+#    #+#             */
/*   Updated: 2022/09/20 10:58:16 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	height(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
		i++;
	return (i - 1);
}

int	length(char **tab)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (tab[1][i])
		i++;
	return (i);
}

int	find_len_max(char **tab)
{
	int	l;
	int	h;

	l = length(tab);
	h = height(tab);
	if (l > h)
		return (h);
	return (l);
}
