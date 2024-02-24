/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:48:53 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 08:18:33 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_block(t_cmdline *cmdline)
{
	t_block	*block;
	int		fd[2];
	int		std_fd[2];

	fd[0] = -1;
	fd[1] = -1;
	block = (t_block *)cmdline;
	std_fd[0] = ft_dup(0, 0);
	std_fd[1] = ft_dup(1, 1);
	if (block->io)
		if (ft_redirect_io(block->io, fd, fd + 1) < 0)
			return ;
	fd[0] > 0 && ft_dup(fd[0], 0);
	fd[1] > 1 && ft_dup(fd[1], 1);
	ft_exc_cmdline(block->cmdline);
	ft_dup(std_fd[0], 0);
	ft_dup(std_fd[1], 1);
}
