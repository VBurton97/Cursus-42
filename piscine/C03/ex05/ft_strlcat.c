/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:29:48 by vburton           #+#    #+#             */
/*   Updated: 2022/09/13 18:51:04 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	t;
	unsigned int	t_dest;
	unsigned int	t_src;

	i = 0;
	t_dest = my_strlen(dest);
	t_src = my_strlen(src);
	t = size - 1;
	if (size - 1 < t_dest)
		return (size + t_src);
	while (src[i] != '\0' && i + t_dest < t)
	{
		dest[t_dest + i] = src[i];
		i++;
	}
	dest[t_dest + i] = '\0';
	return (t_dest + t_src);
}
