/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:46:15 by amatta            #+#    #+#             */
/*   Updated: 2023/07/07 12:37:22 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_free_struct(t_pipex *piping)
{
	ft_free(piping->cmd1);
	ft_free(piping->cmd2);
	ft_free(piping->all_paths);
}

void	child_process1(t_pipex piping, int i, char **env)
{
	char	*temp;

	dup2(piping.infile, STDIN_FILENO);
	dup2(piping.pipefd[1], STDOUT_FILENO);
	close(piping.pipefd[0]);
	close(piping.pipefd[1]);
	close(piping.infile);
	close(piping.outfile);
	while (piping.all_paths[i])
	{
		piping.real_path = ft_strjoin(piping.all_paths[i], "/");
		temp = piping.real_path;
		piping.real_path = ft_strjoin(piping.real_path, piping.cmd1[0]);
		free(temp);
		execve(piping.real_path, piping.cmd1, env);
		free(piping.real_path);
		i++;
	}
	ft_free_struct(&piping);
	put_error("command not found");
	exit(1);
}

void	child_process2(t_pipex piping, int i, char **env)
{
	char	*temp;

	dup2(piping.outfile, STDOUT_FILENO);
	dup2(piping.pipefd[0], STDIN_FILENO);
	close(piping.pipefd[1]);
	close(piping.pipefd[0]);
	close(piping.infile);
	close(piping.outfile);
	while (piping.all_paths[i])
	{
		piping.real_path = ft_strjoin(piping.all_paths[i], "/");
		temp = piping.real_path;
		piping.real_path = ft_strjoin(piping.real_path, piping.cmd2[0]);
		free(temp);
		execve(piping.real_path, piping.cmd2, env);
		free(piping.real_path);
		i++;
	}
	ft_free_struct(&piping);
	put_error("command not found");
	exit(1);
}
