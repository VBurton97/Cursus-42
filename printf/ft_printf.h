/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:29:29 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 15:07:49 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# define EXA_DOWN	"0123456789abcdef"
# define EXA_UP		"0123456789ABCDEF"

int	ft_putchar(char c);
int	ft_putnbr_base(unsigned int nbr, char *base, int len);
int	ft_putnbr(int n, int len);
int	ft_putstr(char *s);
int	ft_printf(const char *str, ...);
int	ft_putnbr_base_exa(unsigned long long nbr, int len);
int	ft_putnbr_unsigned(int n, int len);

#endif
