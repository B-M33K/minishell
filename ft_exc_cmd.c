/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 05:45:04 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:07:11 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_cmd(t_cmdline *cmdline, char **env)
{
	t_cmd		*cmd;
	char		*expanded_cmd;
	pid_t		pid;
	int			fd[2];
	int			std_fd[2];

	(void)env;
	cmd = (t_cmd *) cmdline;
	fd[0] = -1;
	fd[1] = -1;
	if (cmd->io)
		ft_redirect_io(cmd->io, fd, fd + 1);
	std_fd[0] = ft_dup(0, 0);
	std_fd[1] = ft_dup(1, 1);
	if (fd[0] > 0)
		ft_dup(fd[0], 0);
	if (fd[1] > 1)
		ft_dup(fd[1], 1);
	expanded_cmd = ft_expand_var(cmd->cmd, 1);
	cmd->args = ft_split(expanded_cmd, ' ');
	ft_free(&expanded_cmd);
	if (ft_is_builtins(*(cmd->args), &(cmd->builtins)))
		cmd->builtins(cmd->args);
	else
	{
		pid = ft_fork();
		if (!pid)
		{
			signal(SIGQUIT, SIG_DFL);
			cmd->path = ft_absolute_path(*(cmd->args));
			if (!cmd->path)
				exit(g_exit);
			ft_execve(cmd->path, cmd->args, env);
		}
		waitpid(pid, &g_exit, 0);
		if (WIFSIGNALED(g_exit) && isatty(0))
		{
			ft_putendl_fd("Quit: 3", 2);
			g_exit = 131;
		}
		if (WIFEXITED(g_exit))
			g_exit = WEXITSTATUS(g_exit);
	}
	ft_dup(std_fd[0], 0);
	ft_dup(std_fd[1], 1);
}
