/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:15:30 by vburton           #+#    #+#             */
/*   Updated: 2022/09/07 08:55:43 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_maj(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_alphanum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') \
			|| (c >= '0' && c <= '9' ))
		return (1);
	return (0);
}

int	premier_caractere(char *c, int i)
{	
	if (c[0] > 96 && c[0] <= 123)
	{
		c[0] = (c[0] - 32);
		return (1);
	}
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	alpha;
	int	maj_0;
	int	maj_1;
	int	num;

	i = 0;
	while (str[i] != '\0')
	{
		i = premier_caractere(str, i);
		alpha = is_alphanum(str[i]);
		if (alpha == 1)
		{
			maj_0 = is_maj(str[i - 1]);
			maj_1 = is_maj(str[i]);
			alpha = is_alphanum(str[i - 1]);
			num = is_num(str[i]);
			if (alpha == 0 && maj_1 == 0 && num == 0)
				str[i] = (str[i] - 32);
			else if (maj_1 == 1 && alpha == 1)
				str[i] = (str[i] + 32);
		}
		i++;
	}
	return (str);
}
