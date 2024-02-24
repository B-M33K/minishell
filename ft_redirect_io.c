/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:07:52 by obahi             #+#    #+#             */
/*   Updated: 2023/08/12 10:39:22 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_io(t_io *io, int *fd_in, int *fd_out)
{
	while (io)
	{
		if (io->type == T_LESS || io->type == T_LLESS)
			ft_redirect_input(io, fd_in);
		else
			ft_redirect_output(io, fd_out);
		if (g_exit)
			return ;
		io = io->next;
	}
}