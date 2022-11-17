/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:29:29 by vburton           #+#    #+#             */
/*   Updated: 2022/11/17 18:46:30 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr_base(int nbr, char *base, int len);
int	ft_putnbr(int n, int len);
int	ft_putstr(char *s);
int	ft_printf(const char *str, ...);
int	ft_putnbr_base_exa(unsigned long long nbr, char *base, int len);

#endif
