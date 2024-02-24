/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:26:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 14:51:48 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect_file(t_io *in_file, int *fd_in)
{
	char	*file;
	char	*tmp;

	file = ft_expand(in_file->filename);
	if (ft_ambiguous_redirect(file))
	{
		tmp = ft_strtrim(in_file->filename, "\"");
		ft_panic(tmp, "ambiguous redirect", 1);
		ft_free(&tmp);
	}
	else
	{
		if (!ft_strncmp(file, "*", 1))
			ft_panic(in_file->filename, "ambiguous redirect", 1);
		else
			*fd_in = ft_open(file, O_RDONLY, 0);
		ft_free(&file);
	}
	return (*fd_in);
}

int	ft_redirect_input(t_io *in_file, int *fd_in)
{
	char	*file;
	int		i;

	if (in_file->type == T_LESS)
		*fd_in = ft_redirect_file(in_file, fd_in);
	else
	{
		file = in_file->filename;
		i = !ft_strchr(file, 34) * !ft_strchr(file, 39);
		if (*fd_in > 0)
			close(*fd_in);
		*fd_in = ft_here_doc_file(in_file->content, i);
	}
	return (*fd_in);
}
