/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:33 by amatta            #+#    #+#             */
/*   Updated: 2023/07/07 13:10:36 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipex *piping, char **argv, char **env, int i)
{
	piping->infile = open(argv[1], O_RDONLY);
	if (piping->infile == -1)
		put_error("No such file or directory");
	piping->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (piping->outfile == -1)
		put_error("No such file or directory");
	piping->cmd1 = ft_split(argv[2], ' ');
	piping->cmd2 = ft_split(argv[3], ' ');
	if (pipe(piping->pipefd) == -1)
		put_error("Pipe error");
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	piping->all_paths = ft_split(env[i], ':');
	piping->all_paths[0] = ft_strtrim(piping->all_paths[0], "PATH=");
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	piping;
	int		i;

	if (argc == 5)
	{
		i = 0;
		init_struct(&piping, argv, env, i);
		piping.cpid1 = fork();
		if (piping.cpid1 == -1)
			put_error("Fork error");
		i = 0;
		if (piping.cpid1 == 0)
			child_process1(piping, i, env);
		waitpid(piping.cpid1, NULL, 0);
		piping.cpid2 = fork();
		if (piping.cpid2 == -1)
			put_error("Fork error");
		i = 0;
		if (piping.cpid2 == 0)
			child_process2(piping, i, env);
		waitpid(piping.cpid2, NULL, 0);
		ft_free_struct(&piping);
	}
	else
		put_error("PIPEX needs 4 arguments!");
}
