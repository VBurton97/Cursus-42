/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:17:53 by victor            #+#    #+#             */
/*   Updated: 2023/01/06 15:25:20 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex *pipex, char **argv, char **envp)
{
	pipex->input = open(argv[1], O_RDONLY);
	if (pipex->input == -1)
		sec_open_input(pipex);
	pipex->final_file_path = get_path_cmd(pipex, envp, pipex->cmd1[0]);
	if (pipex->final_file_path == NULL)
		sec_path(pipex);
	if (dup2(pipex->input, STDIN_FILENO) == -1)
		sec_dup2(pipex);
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		sec_dup2(pipex);
	if (close(pipex->fd[0]) == -1)
		sec_close(pipex);
	if (close(pipex->fd[1]) == -1)
		sec_close(pipex);
	if (close(pipex->input) == -1)
		sec_close(pipex);
	if (execve(pipex->final_file_path, pipex->cmd1, NULL) == -1)
		sec_execve(pipex);
}

void	ft_child2(t_pipex *pipex, char **argv, char **envp)
{
	pipex->output = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->output == -1)
		sec_open_output(pipex);
	pipex->final_file_path = get_path_cmd(pipex, envp, pipex->cmd2[0]);
	if (pipex->final_file_path == NULL)
		sec_path(pipex);
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		sec_dup2(pipex);
	if (dup2(pipex->output, STDOUT_FILENO) == -1)
		sec_dup2(pipex);
	if (close(pipex->fd[0]) == -1)
		sec_close(pipex);
	if (close(pipex->fd[1]) == -1)
		sec_close(pipex);
	if (close(pipex->output) == -1)
		sec_close(pipex);
	if (execve(pipex->final_file_path, pipex->cmd2, NULL) == -1)
		sec_execve(pipex);
}

void	ft_exec(t_pipex	*pipex, char **argv, char **envp)
{
	pipex->ft_pipe = pipe(pipex->fd);
	if (pipex->ft_pipe == -1)
		ft_printf("An error has occured while opening the pipe.\n");
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		sec_fork(pipex);
	if (pipex->pid1 == 0)
		ft_child1(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		sec_fork(pipex);
	if (pipex->pid2 == 0)
		ft_child2(pipex, argv, envp);
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
		sec_split(&pipex);
	ft_exec(&pipex, argv, envp);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
