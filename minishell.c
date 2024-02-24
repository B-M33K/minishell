/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:07:11 by obahi             #+#    #+#             */
/*   Updated: 2024/02/24 09:11:41 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(char **argv, char **envp)
{
	(void) argv;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	g_.ext = 0;
	ft_default_env(envp);
	rl_catch_signals = 0;
}

int	ft_process_null_line(int stdin_fd)
{
	if (!isatty(0))
	{
		ft_dup(stdin_fd, 0);
		g_.ext = 1;
		return (1);
	}
	else
	{
		write(1, "exit\n", 5);
		return (2);
	}
	return (0);
}

void	ft_run(char *line)
{
	t_cmdline	*cmdline;
	char		*tmp;

	tmp = line;
	if (*line != '\0')
		add_history(line);
	cmdline = 0;
	if (ft_syntax_analysis(line) == 1)
	{
		cmdline = ft_parce_cmdline(&line);
		if (cmdline)
		{
			ft_exc_cmdline(cmdline);
		}
		ft_free_cmdline(cmdline);
	}
	ft_free(&tmp);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		*token;
	int			stdin_fd;

	if (argc > 1)
		return (ft_panic("minishell", "too many arguments", 1), 1);
	token = 0;
	ft_init(argv, envp);
	while (1)
	{
		stdin_fd = ft_dup(0, 0);
		line = readline("minishel1 $ ");
		if (!line)
		{
			if (ft_process_null_line(stdin_fd) == 1)
				continue ;
			break ;
		}
		ft_run(line);
		if (!isatty(0))
			ft_dup(stdin_fd, 0);
		else
			close(stdin_fd);
	}
	return (ft_free(&g_.path), ft_free2(g_.environ), 0);
}
