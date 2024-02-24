/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:26:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 12:53:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_input(t_io *in_file, int *fd_in)
{
	char	*file;
	char	*tmp;

	if (in_file->type == T_LESS)
	{
		file = ft_expand_var(in_file->filename, 0);
		if (!file)
		{
			tmp = ft_strtrim(in_file->filename, "\"");
			ft_panic(tmp, "ambiguous redirect");
			g_exit = 1;
			ft_free(&tmp);
		}
		else
		{
			if (!ft_strncmp(file, "*", 1))
			{
				ft_panic(in_file->filename, "ambiguous redirect");
				g_exit = 1;
			}
			else if (!access(file, F_OK))
			{
				if (access(file, R_OK))
				{
					ft_panic(file, "Permission denied");
					g_exit = 1;
				}
				else
				{
					if (*fd_in > 0)
						close(*fd_in);
					*fd_in = ft_open(file, O_RDONLY, 0);
				}
			}
			else
			{
				ft_panic(file, "No such file or directory");
				g_exit = 1;
			}
			ft_free(&file);
		}
	}
	else
	{
		if (*fd_in > 0)
			close(*fd_in);
		*fd_in = ft_here_doc_file(in_file->content, !ft_strchr(in_file->filename, 34)*!ft_strchr(in_file->filename, 39));
	}
}
