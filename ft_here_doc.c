/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:59:43 by obahi             #+#    #+#             */
/*   Updated: 2023/08/16 10:04:16 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_content	*ft_here_doc(char	*limiter, int *he_status)
{
	t_content	*content;
	char		*delimiter;
	char		*line;
	char		*tmp;
	int			n;
	int			stdin_fd;

	content = 0;
	*he_status = 0;
	stdin_fd = ft_dup(0, 0);
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	delimiter = ft_delimiter(limiter);
	n = ft_strlen(delimiter);
	line = readline("> ");
	while (line && (ft_strncmp(line, delimiter, n) || *(line + n)))
	{
		ft_add_content(&content, ft_new_content(line));
		tmp = line;
		line = readline("> ");
		ft_free(&tmp);
	}
	ft_free(&line);
	ft_free(&delimiter);
	if (!line)
	{
		if (!isatty(0))
		{
			ft_dup(stdin_fd, 0);
			ft_free_content(content);
			*he_status = -1;
			g_exit = 1;
			return (0);
		}
	}
	return (content);
}
