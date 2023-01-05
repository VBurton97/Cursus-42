/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:27:22 by vburton           #+#    #+#             */
/*   Updated: 2023/01/05 15:32:12 by vburton          ###   ########.fr       */
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
void	sec_open_input(t_pipex *pipex);
void	sec_open_output(t_pipex *pipex);
void	sec_close(t_pipex *pipex);
void	sec_dup2(t_pipex *pipex);
void	sec_split(t_pipex *pipex);
void	sec_path(t_pipex *pipex);
void	sec_execve(t_pipex *pipex);

#endif
