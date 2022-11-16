/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:35:14 by victor            #+#    #+#             */
/*   Updated: 2022/11/16 20:42:59 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdarg.h>

int	ft_case(char c, va_list res)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar((char)res[0]);
	else if (c == 's')
		i = ft_putsr((char *)res);
	else if (c == 'p')
		i = ft_convert_base(&res, "0123456789", "0123456789abcdef");
	else if (c == 'd')
		i = ft_putnbr_dec((int *)res, c);
	else if (c == 'i')
		i = ft_putnbr((int *)res);
	else if (c == 'u')
		i = ft_putnbr_dec((int *)res, c);
	else if (c == 'x')
		i = ft_convert_base((char *)res, "0123456789", "0123456789abcdef");
	else if (c == 'X')
		i = ft_convert_base((char *)res, "0123456789", "0123456789ABCDEF");
	else (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		ibis;

	i = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i - 1] != '%')
			ft_case(str[i+1], lst);
		else
			ft_putchar(str[i]);
	}
	return (i)
}