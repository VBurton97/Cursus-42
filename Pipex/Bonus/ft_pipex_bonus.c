/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:17:53 by victor            #+#    #+#             */
/*   Updated: 2023/01/06 17:31:41 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child1(t_pipex *pipex, char **argv, char **envp, int fd[])
{
	pipex->input = open(argv[1], O_RDONLY);
	if (pipex->input == -1)
		sec_open_input(pipex);
	pipex->final_file_path = get_path_cmd(pipex, envp, pipex->cmd1[0]);
	if (pipex->final_file_path == NULL)
		sec_path(pipex);
	if (dup2(pipex->input, STDIN_FILENO) == -1)
		sec_dup2(pipex);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		sec_dup2(pipex);
	if (close(fd[0]) == -1)
		sec_close(pipex);
	if (close(fd[1]) == -1)
		sec_close(pipex);
	if (close(pipex->input) == -1)
		sec_close(pipex);
	if (execve(pipex->final_file_path, pipex->cmd1, NULL) == -1)
		sec_execve(pipex);
}

void	ft_child2(t_pipex *pipex, char **argv, char **envp, int fd[])
{
	pipex->output = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->output == -1)
		sec_open_output(pipex);
	pipex->final_file_path = get_path_cmd(pipex, envp, pipex->cmd2[0]);
	if (pipex->final_file_path == NULL)
		sec_path(pipex);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		sec_dup2(pipex);
	if (dup2(pipex->output, STDOUT_FILENO) == -1)
		sec_dup2(pipex);
	if (close(fd[0]) == -1)
		sec_close(pipex);
	if (close(fd[1]) == -1)
		sec_close(pipex);
	if (close(pipex->output) == -1)
		sec_close(pipex);
	if (execve(pipex->final_file_path, pipex->cmd2, NULL) == -1)
		sec_execve(pipex);
}

int	main(int argc, char **argv, char **envp)
{

	int	fd[argc - 3];
	t_pipex	pipex;

	pipex.i = 2;
	pipex.cmd1 = ft_split(argv[pipex.i], ' ');
	pipex.cmd1 = ft_split(argv[pipex.i], ' ');
	if (pipex.cmd1 == NULL || pipex.cmd2 == NULL)
		sec_split(&pipex);
	pipex.ft_pipe = pipe(fd);
	if (pipex.ft_pipe == -1)
		ft_printf("An error has occured while opening the pipe.\n");
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		sec_fork(&pipex);
	if (pipex.pid1 == 0)
		ft_child1(&pipex, argv, envp, fd);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		sec_fork(&pipex);
	if (pipex.pid2 == 0)
		ft_child2(&pipex, argv, envp, fd);
	ft_close(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
