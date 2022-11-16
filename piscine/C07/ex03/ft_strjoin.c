/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:38:28 by vburton           #+#    #+#             */
/*   Updated: 2022/09/22 00:16:24 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *str, char *res)
{
	int	j;
	int	len_res;

	j = 0;
	len_res = ft_strlen(res);
	while (str[j])
	{
		res[len_res] = str[j];
		len_res++;
		j++;
	}
	res[len_res] = '\0';
}

int	size_res(int size, char **str, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		if (i < size)
			len = len + ft_strlen(str[i]);
		if (i < size - 1)
			len = len + ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	j = 0;
	res = NULL;
	len = size_res(size, str, sep);
	res = malloc(sizeof(char) * (len + 1));
	if (! res)
		return (res);
	res[0] = '\0';
	while (j < size)
	{
		if (j < size)
			ft_strcat(str[j], res);
		if (j < size - 1)
			ft_strcat(sep, res);
		j++;
	}
	res[len] = '\0';
	return (res);
}
