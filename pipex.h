/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:52:37 by amatta            #+#    #+#             */
/*   Updated: 2023/07/07 12:36:40 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	cpid1;
	pid_t	cpid2;
	char	**cmd1;
	char	**cmd2;
	char	**all_paths;
	char	*real_path;
}	t_pipex;

void	child_process1(t_pipex piping, int i, char **env);
void	child_process2(t_pipex piping, int i, char **env);
void	init_struct(t_pipex *piping, char **argv, char **env, int i);
void	put_error(char *s);
void	ft_free(char **split);
void	ft_free_struct(t_pipex *piping);

#endif
