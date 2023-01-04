/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:51:32 by vburton           #+#    #+#             */
/*   Updated: 2023/01/04 17:31:43 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sec_open_input(void)
{
	perror("Error opening file");
	exit(1);
}

void	sec_open_output(void)
{
	perror("Error opening file");
	exit(1);
}

void	sec_close(void)
{
	perror("Error closing file");
	exit(1);
}
