/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:54:02 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 16:39:31 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	ft_fork_left_right(t_cmdline *next, int t[2], int i)
{
	pid_t	pid;

	pid = ft_fork();
	if (!pid)
	{
		ft_dup(t[i], i);
		close(t[(i + 1) % 2]);
		ft_exc_cmdline(next);
		exit(g_.ext);
	}
	return (pid);
}

void	ft_exc_pipe(t_cmdline *cmdline)
{
	t_pipe	*pip;
	int		ret;
	int		t[2];
	pid_t	pid[2];

	ret = pipe(t);
	if (ret < 0)
	{
		ft_perror("minishell : ", 1);
		return ;
	}
	pip = (t_pipe *) cmdline;
	pid[0] = ft_fork_left_right(pip->left, t, 1);
	pid[1] = ft_fork_left_right(pip->right, t, 0);
	close(t[0]);
	close(t[1]);
	waitpid(pid[1], &g_.ext, 0);
	if (WIFEXITED(g_.ext))
		g_.ext = WEXITSTATUS(g_.ext);
	waitpid(pid[0], 0, 0);
}
