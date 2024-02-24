/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:53:58 by obahi             #+#    #+#             */
/*   Updated: 2023/08/12 10:38:46 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_block(t_cmdline *cmdline)
{
	t_block	*block;

	block = (t_block *)cmdline;
	if (block)
	{
		ft_free_cmdline(block->cmdline);
		if (block->io)
			ft_free_io(block->io);
		free(block);
	}
}
