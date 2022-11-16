/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:22:19 by vburton           #+#    #+#             */
/*   Updated: 2022/09/06 18:28:31 by vburton          ###   ########lyon.fr   */
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

char	*ft_strcat(char	*dest, char	*src)
{
	int	t_dest;
	int	i;

	t_dest = my_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[t_dest] = src[i];
		i++;
		t_dest++;
	}
	dest[t_dest] = '\0';
	return (dest);
}
