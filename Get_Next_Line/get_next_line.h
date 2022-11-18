/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:25:50 by vburton           #+#    #+#             */
/*   Updated: 2022/11/18 18:12:43 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define BUFF_SIZE 10

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);

# endif
