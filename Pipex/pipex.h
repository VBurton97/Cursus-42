/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:27:22 by vburton           #+#    #+#             */
/*   Updated: 2023/01/04 17:01:33 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_pipex
{
	int		ft_pipe;
	int		fd[2];
	int		pid1;
	int		pid2;
	int		input;
	int		output;
	char	**cmd1;
	char	**cmd2;
	char	*path;
	char	**cmd_path;
	char	*final_file_path;
}							t_pipex;

char	*get_path(char **path, char *cmd);
char	*grep_path(char **envp);
void	ft_close(t_pipex *pipex);
void	sec_open_input(void);
void	sec_open_output(void);
void	sec_close(void);

#endif
