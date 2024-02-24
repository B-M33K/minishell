/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:07:11 by obahi             #+#    #+#             */
/*   Updated: 2024/02/24 09:07:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char		*line;
	char 		*tmp;
	t_cmdline	*cmdline;
	int			stdin_fd;

	(void) argc;
	(void) argv;
	line = 0;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_default_env();
	while (1)
	{
		rl_catch_signals = 0;
		stdin_fd = ft_dup(0, 0);
		line = readline("b_meek311 $ ");
		if (!line)
		{
			if (!isatty(0))
			{
				ft_dup(stdin_fd, 0);
				continue;
			}
			write(1, "exit", 4);
			break;
		}
		tmp = line;
		if (*line != '\0')
			add_history(line);
		if (ft_syntax_analysis(line) == 1)
		{
			cmdline = ft_parce_cmdline(&line);
			if (cmdline)
			{
				// to visualize the tree that has been buit
				ft_print_line(cmdline, 1);
				ft_exc_cmdline(cmdline, environ);
				ft_free_cmdline(cmdline);
			}
		}
		ft_free(&tmp);
	}
	
	return (0);
}
