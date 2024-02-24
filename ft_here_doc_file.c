/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:32:34 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 15:28:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_content_2_file(t_content *content, int fd, int expand)
{
	char	*tmp;

	if (expand)
	{
		while (content)
		{
			tmp = ft_he_expand(content->line);
			ft_putendl_fd(tmp, fd);
			ft_free(&tmp);
			content = content->next;
		}
	}
	else
	{
		while (content)
		{
			ft_putendl_fd(content->line, fd);
			content = content->next;
		}
	}
}

int	ft_here_doc_file(t_content	*content, int expand)
{
	static int	i;
	int			fd;
	int			fd2;
	char		*file;
	char		*tmp;

	tmp = ft_itoa(i++);
	file = ft_strjoin(HERE_DOC, tmp);
	ft_free(&tmp);
	tmp = 0;
	fd = ft_open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fd2 = ft_open(file, O_RDONLY, 0);
	ft_content_2_file(content, fd, expand);
	close(fd);
	ft_free(&file);
	return (fd2);
}
