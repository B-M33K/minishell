/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:54:02 by obahi             #+#    #+#             */
/*   Updated: 2023/08/13 09:17:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_pipe(t_cmdline *cmdline, char **env)
{
	t_pipe	*pip;
	int		ret;
	int		t[2];
	int		pid;

	ret = pipe(t);
	if (ret < 0)
		perror("minishell : ");
	pip = (t_pipe *) cmdline;
	pid = ft_fork();
	if (!pid)
	{
		ft_dup(t[1], 1);
		close(t[0]);
		ft_exc_cmdline(pip->left, env);
		exit(g_exit);
	}
	pid = ft_fork();
	if (!pid)
	{
		ft_dup(t[0], 0);
		close(t[1]);
		ft_exc_cmdline(pip->right, env);
		exit(g_exit);
	}
	close(t[0]);
	close(t[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}
