/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:49:02 by vburton           #+#    #+#             */
/*   Updated: 2022/09/07 12:45:29 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	count;
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (&str[0]);
	count = my_strlen(to_find);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (j == count)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
