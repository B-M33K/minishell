/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:59:43 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 16:02:50 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_content	*ft_read_content(char *del, int std_in, int *he_stats)
{
	t_content	*cntnt;
	char		*line;

	line = 0;
	cntnt = 0;
	line = readline("> ");
	while (line && ft_strcmp(line, del) != 0)
	{
		ft_add_content(&cntnt, ft_new_content(line));
		ft_free(&line);
		line = readline("> ");
	}
	if (!line)
	{
		if (!isatty(0))
		{
			ft_dup(std_in, 0);
			ft_free_content(cntnt);
			*he_stats = -1;
			g_.ext = 1;
			return (0);
		}
	}
	return (close(std_in), ft_free(&line), cntnt);
}

t_content	*ft_here_doc(char	*limiter, int *he_status)
{
	t_content	*content;
	char		*delimiter;
	int			stdin_fd;

	content = 0;
	delimiter = 0;
	*he_status = 0;
	stdin_fd = ft_dup(0, 0);
	signal(SIGINT, ft_heredoc_sigint);
	signal(SIGQUIT, SIG_IGN);
	delimiter = ft_delimiter(limiter);
	content = ft_read_content(delimiter, stdin_fd, he_status);
	ft_free(&delimiter);
	return (content);
}
