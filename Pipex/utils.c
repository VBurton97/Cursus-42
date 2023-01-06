/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton < vburton@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:57:06 by vburton           #+#    #+#             */
/*   Updated: 2023/01/06 16:20:52 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char	**tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_close(t_pipex *pipex)
{
	if (close(pipex->fd[0]) == -1)
		sec_close(pipex);
	if (close(pipex->fd[1]) == -1)
		sec_close(pipex);
	if (close(pipex->ft_pipe) == -1)
		sec_close(pipex);
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
}

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

char	*get_path_cmd(t_pipex *pipex, char **envp, char	*cmd)
{
	if (access(pipex->cmd1[0], 0) == 0)
		pipex->final_file_path = cmd;
	else
	{
		pipex->path = grep_path(envp);
		pipex->cmd_path = ft_split(pipex->path, ':');
		if (pipex->cmd_path == NULL)
			sec_split(pipex);
		pipex->final_file_path = get_path(pipex->cmd_path, cmd);
	}
	return (pipex->final_file_path);
}
