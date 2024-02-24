/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 05:45:04 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 00:25:17 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_retreive_exit_status(void)
{
	if (WIFEXITED(g_.ext))
		g_.ext = WEXITSTATUS(g_.ext);
	else if (WIFSIGNALED(g_.ext))
	{
		(g_.ext == 3) && printf("Quit: %d\n", g_.ext);
		(g_.ext == 2) && printf("\n");
		g_.ext = WTERMSIG(g_.ext) + 128;
	}
}

void	ft_command(t_cmd *cmd)
{
	pid_t		pid;

	if (!cmd->args)
	{
		g_.ext = 0;
		return ;
	}
	pid = ft_fork();
	if (!pid)
	{
		signal(SIGQUIT, SIG_DFL);
		cmd->path = ft_absolute_path(*(cmd->args));
		if (!cmd->path)
			exit(g_.ext);
		ft_execve(cmd->path, cmd->args);
	}
	waitpid(pid, &g_.ext, 0);
	ft_retreive_exit_status();
	return ;
}

void	ft_exc_cmd(t_cmdline *cmdline)
{
	t_content	*content;
	t_cmd		*cmd;
	int			fd[2];
	int			std_fd[2];

	cmd = (t_cmd *) cmdline;
	fd[0] = -1;
	fd[1] = -1;
	if (cmd->io)
		if (ft_redirect_io(cmd->io, fd, fd + 1) < 0)
			return ;
	std_fd[0] = ft_dup(0, 0);
	std_fd[1] = ft_dup(1, 1);
	fd[0] > 0 && ft_dup(fd[0], 0);
	fd[1] > 1 && ft_dup(fd[1], 1);
	content = cmd->content;
	cmd->content = ft_expand_content(cmd->content);
	ft_free_content(content);
	cmd->args = ft_lst_2_char__(cmd->content);
	if (cmd->args && ft_is_builtins(*(cmd->args), &(cmd->builtins)))
		cmd->builtins(cmd->args);
	else
		ft_command(cmd);
	ft_dup(std_fd[0], 0);
	ft_dup(std_fd[1], 1);
}
