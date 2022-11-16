/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:40:56 by vburton           #+#    #+#             */
/*   Updated: 2022/09/22 11:01:37 by vburton          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	tab_operand(t_fcts *f)
{
	f[0].operand = "+";
	f[0].fct = &plus;
	f[1].operand = "-";
	f[1].fct = &minus;
	f[2].operand = "/";
	f[2].fct = &divide;
	f[3].operand = "*";
	f[3].fct = &multiply;
	f[4].operand = "%";
	f[4].fct = &modulo;
}
