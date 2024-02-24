/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:21 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 14:51:24 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect_output(t_io *out_file, int *fd_out)
{
	char	*file;

	file = ft_expand(out_file->filename);
	if (ft_ambiguous_redirect(file))
		ft_panic(out_file->filename, "ambiguous redirect", 1);
	else
	{
		if (!ft_strncmp(file, "*", 1))
			ft_panic(out_file->filename, "ambiguous redirect", 1);
		else
		{
			if (*fd_out > 1)
				close(*fd_out);
			if (out_file->type == T_GREAT)
				*fd_out = ft_open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				*fd_out = ft_open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		ft_free(&file);
	}
	return (*fd_out);
}
