/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:57:06 by vburton           #+#    #+#             */
/*   Updated: 2023/01/03 21:44:55 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **path, char *cmd)
{
	char	*buf;
	char	*cmd_buf;

	while (*path)
	{
		buf = ft_strjoin(*path, "/");
		cmd_buf = ft_strjoin(buf, cmd);
		free (buf);
		if (access(cmd_buf, 0) == 0)
			return (cmd_buf);
		free(cmd_buf);
		path++;
	}
	return (NULL);
}

char	*grep_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
	{
		envp++;
	}
	return (*envp + 5);
}

void	ft_close(t_pipex *pipex)
{
	free(pipex->cmd1);
	free(pipex->cmd2);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->output);
	close(pipex->input);

}
