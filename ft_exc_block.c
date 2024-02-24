/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:48:53 by obahi             #+#    #+#             */
/*   Updated: 2023/08/12 11:11:15 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_block(t_cmdline *cmdline, char **env)
{
	t_block	*block;
	int		fd[2];
	int		std_fd[2];
	
	fd[0] = -1;
	fd[1] = -1;
	std_fd[0] = -1;
	std_fd[0] = -1;
	block = (t_block *)cmdline;
	if (block->io)
	{
		std_fd[0] = ft_dup(0, 0);
		std_fd[1] = ft_dup(1, 1);
		ft_redirect_io(block->io, fd, fd + 1);
		if (fd[0] > 0)
			ft_dup(fd[0], 0);
		if (fd[1] > 1)
			ft_dup(fd[1], 1);
	}
	ft_exc_cmdline(block->cmdline, env);
	if (std_fd[0] > 0)
		ft_dup(std_fd[0], 0);
	if (std_fd[1] > 1)
		ft_dup(std_fd[1], 1);
}
