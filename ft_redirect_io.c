/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:07:52 by obahi             #+#    #+#             */
/*   Updated: 2023/08/22 01:39:29 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect_io(t_io *io, int *fd_in, int *fd_out)
{
	int	ret;

	while (io)
	{
		if (io->type == T_LESS || io->type == T_LLESS)
			ret = ft_redirect_input(io, fd_in);
		else
			ret = ft_redirect_output(io, fd_out);
		if (ret < 0)
			break ;
		io = io->next;
	}
	return (ret);
}
