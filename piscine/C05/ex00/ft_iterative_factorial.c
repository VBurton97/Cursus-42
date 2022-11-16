/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:54:12 by vburton           #+#    #+#             */
/*   Updated: 2022/09/13 13:36:23 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int n)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	while (i < n && n > 0)
	{
		res = res * (n - i);
		i++;
	}
	return (res);
}
