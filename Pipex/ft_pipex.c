/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:17:53 by victor            #+#    #+#             */
/*   Updated: 2023/01/02 18:58:28 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int ft_pipe;
    int fd[2];
    int pid1;
    char *cmd1;
    char *cmd2;


    if (argc != 5)
        return (ft_printf("incorrect number of argument\n"), 0);
    cmd1 = ft_split(argv[2]);
    cmd2 = ft_split(argv[3]);
    fd[0] = open(argv[1], O_RDONLY);
    fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0777);
    ft_pipe = pipe(fd);
    if (ft_pipe == -1)
        ft_printf("An error has occured while opening the pipe.\n");
    pid1 = fork();
    if (pid1 == 0)
    {
        dup2(fd[0], STDOUT_FILENO);
        close fd[0];
        close fd[1];
        execve()
    }
    
}