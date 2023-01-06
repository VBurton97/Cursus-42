/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:51:32 by vburton           #+#    #+#             */
/*   Updated: 2023/01/06 17:18:00 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	sec_open_input(t_pipex *pipex)
{
	perror("Error opening file");
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	exit(0);
}

void	sec_open_output(t_pipex *pipex)
{
	perror("Error opening file");
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	exit(0);
}

void	sec_close(t_pipex *pipex)
{
	perror("Error closing file");
	free(pipex->cmd_path);
	free(pipex->final_file_path);
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	exit(0);
}

void	sec_dup2(t_pipex *pipex)
{
	perror("Error duplicating the processus");
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	exit(0);
}

void	sec_split(t_pipex *pipex)
{
	ft_printf("An error as occured while executing the split fonction\n");
	if (pipex->cmd1)
		free_split(pipex->cmd1);
	if (pipex->cmd2)
		free_split(pipex->cmd2);
	exit(0);
}

void	sec_path(t_pipex *pipex)
{
	ft_printf("An error as occured while building the path\n");
	free(pipex->cmd_path);
	free(pipex->final_file_path);
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	exit(0);
}

void	sec_execve(t_pipex *pipex)
{
	perror("Error while executing ft_fils2\n");
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	exit(0);
}

void	sec_fork(t_pipex *pipex)
{
	perror("An error as occured while forking");
	ft_close(pipex);
	exit(0);
}
