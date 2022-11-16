/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:24:17 by vburton           #+#    #+#             */
/*   Updated: 2022/09/06 18:30:57 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	my_strlen(char	*src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	int				t_dest;
	unsigned int	i;

	t_dest = my_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[t_dest] = src[i];
		i++;
		t_dest++;
	}
	dest[t_dest] = '\0';
	return (dest);
}
