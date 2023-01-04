/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:17:53 by victor            #+#    #+#             */
/*   Updated: 2023/01/04 17:44:42 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fils1(t_pipex *pipex, char **argv, char **envp)
{
	pipex->input = open(argv[1], O_RDONLY);
	if (pipex->input == -1)
		sec_open_input();
	pipex->path = grep_path(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (pipex->cmd_path == NULL)

	pipex->final_file_path = get_path(pipex->cmd_path, pipex->cmd1[0]);
	dup2(pipex->input, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	if (close(pipex->fd[0]) == -1)
		sec_close();
	if (close(pipex->fd[1]) == -1)
		sec_close();
	if (close(pipex->input) == -1)
		sec_close();
	if (close(pipex->output) == -1)
		sec_close();
	if (execve(pipex->final_file_path, pipex->cmd1, NULL) == -1)
	{
		perror("Error while executing ft_fils1");
		exit(1);
	}
}

void	ft_fils2(t_pipex *pipex, char **argv, char **envp)
{
	pipex->output = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->output == -1)
		sec_open_output();
	pipex->path = grep_path(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	pipex->final_file_path = get_path(pipex->cmd_path, pipex->cmd2[0]);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->output, STDOUT_FILENO);
	if (close(pipex->fd[0]) == -1)
		sec_close();
	if (close(pipex->fd[1]) == -1)
		sec_close();
	if (close(pipex->input) == -1)
		sec_close();
	if (close(pipex->output) == -1)
		sec_close();
	if (execve(pipex->final_file_path, pipex->cmd2, NULL) == -1)
	{
		perror("Error while executing ft_fils2");
		exit(1);
	}
}

void	ft_exec(t_pipex	*pipex, char **argv, char **envp)
{
	pipex->ft_pipe = pipe(pipex->fd);
	if (pipex->ft_pipe == -1)
		ft_printf("An error has occured while opening the pipe.\n");
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		ft_fils1(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		ft_fils2(pipex, argv, envp);
	ft_close(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("incorrect number of argument\n"), 0);
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	if (pipex.cmd1 == NULL || pipex.cmd2 == NULL)
		return (0);
	ft_exec(&pipex, argv, envp);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return(0);
}
