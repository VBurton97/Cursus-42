/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:02:46 by vburton           #+#    #+#             */
/*   Updated: 2022/09/22 18:56:15 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_swap(char **argv, int i)
{
	char	*buffer;

	buffer = argv[i];
	argv[i] = argv[i + 1];
	argv[i + 1] = buffer;
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i] || s1[i] == '\0')
			return (s1[i] - s2[i]);
		if (s2[i] < s1[i] || s2[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(tab);
	while (j < len - 1)
	{
		i = 0;
		while (i < len - 1)
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(tab, i);
			}
			i++;
		}
		j++;
	}
}
