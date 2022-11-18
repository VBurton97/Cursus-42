/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:53:07 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/09/19 13:52:34 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERR_MAP "map error\n"

int		is_valid_map(char **tab_map);
char	**read_map(char *pwd_map);
char	*open_map(char *pwd_map);
//t_stock	*save_id(char **tab_map);

#endif
