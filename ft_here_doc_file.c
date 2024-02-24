/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:32:34 by obahi             #+#    #+#             */
/*   Updated: 2023/08/16 12:36:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_here_doc_file(t_content	*content, int expand)
{
	static int	i;
	int			fd;
	char		*file;
	char		*tmp;

	tmp = ft_itoa(i++);
	file = ft_strjoin(HERE_DOC, tmp);
	ft_free(&tmp);
	tmp = 0;
	fd = ft_open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (expand)
	{
		while (content)
		{
			tmp = ft_expand_var(content->line, 0);
			ft_putendl_fd(tmp, fd);
			ft_free(&tmp);
			tmp = 0;
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
	close(fd);
	fd = ft_open(file, O_RDONLY, 0);
	ft_free(&file);
	return (fd);
}
