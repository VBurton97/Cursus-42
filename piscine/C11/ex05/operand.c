/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:31:59 by vburton           #+#    #+#             */
/*   Updated: 2022/09/22 16:29:41 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	plus(int a, int b)
{
	int	res;

	res = a + b;
	return (res);
}

int	minus(int a, int b)
{
	int	res;

	res = a - b;
	return (res);
}

int	divide(int a, int b)
{
	int	res;

	res = a / b;
	return (res);
}

int	multiply(int a, int b)
{
	int	res;

	res = a * b;
	return (res);
}

int	modulo(int a, int b)
{
	int	res;

	res = a % b;
	return (res);
}
