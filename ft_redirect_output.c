/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:21 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 08:20:21 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_output(t_io *out_file, int *fd_out)
{
	char	*file;

	file = ft_expand_var(out_file->filename, 0);
	if (!file)
	{
		ft_panic(out_file->filename, "ambiguous redirect");
		g_exit = 1;
	}
	else
	{
		if (!ft_strncmp(file, "*", 1))
		{
			ft_panic(out_file->filename, "ambiguous redirect");
			g_exit = 1;
		}
		else if (!access(out_file->filename, F_OK))
		{
			if (access(out_file->filename, W_OK))
			{
				ft_panic(out_file->filename, "Permission denied");
				g_exit = 1;
			}
			else
			{
				if (*fd_out > 1)
					close(*fd_out);
				if (out_file->type == T_GREAT)
					*fd_out = ft_open(file, O_WRONLY | O_TRUNC, 0);
				else
					*fd_out = ft_open(file, O_WRONLY | O_APPEND, 0);
			}
		}
		else
		{
			if (*fd_out > 1)
				close(*fd_out);
			if (out_file->type == T_GREAT)
				*fd_out = ft_open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				*fd_out = ft_open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
	}
}
