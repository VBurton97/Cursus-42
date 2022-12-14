/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:35:14 by victor            #+#    #+#             */
/*   Updated: 2022/11/21 09:06:41 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case(char c, va_list res, int len)
{
	if (c == 'c')
		len += ft_putchar(va_arg(res, int));
	else if (c == 's')
		len += ft_putstr(va_arg(res, char *));
	else if (c == 'p')
		len = ft_putnbr_base_exa(va_arg(res, unsigned long long), len);
	else if (c == 'd')
		len = ft_putnbr(va_arg(res, int), len);
	else if (c == 'i')
		len = ft_putnbr(va_arg(res, int), len);
	else if (c == 'u')
		len = ft_putnbr_unsigned(va_arg(res, int), len);
	else if (c == 'x')
		len = ft_putnbr_exa(va_arg(res, unsigned long long), EXA_DOWN, len);
	else if (c == 'X')
		len = ft_putnbr_exa(va_arg(res, int), EXA_UP, len);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		ibis;

	i = 0;
	ibis = 0;
	if (write(1, NULL, 0))
		return (-1);
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ibis = ft_case(str[i + 1], lst, ibis);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			ibis++;
		}
		i++;
	}
	va_end(lst);
	return (ibis);
}
