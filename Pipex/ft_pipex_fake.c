/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_fake.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:38 by victor            #+#    #+#             */
/*   Updated: 2023/01/02 17:35:13 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd[2];
	int pid1 = fork();
	int	pid2 = fork();

	if (pipe(fd) == -1)
		return (1);
	if (pid1 < 0 | pid2 < 0)
	{
		perror("fork a echoué");
		return (1);
	}
	if (pid1 == 0)
		dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(argv[1], &argv[2], NULL);

	if (pid2 == 1)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(argv[3], &argv[4], NULL);
	}
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}