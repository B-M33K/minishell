/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:32:23 by obahi             #+#    #+#             */
/*   Updated: 2023/07/29 08:07:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_block(void)
{
	t_block	*block;

	block = malloc(sizeof(t_block));
	if (!block)
		return (0);
	ft_memset(block, 0, sizeof(t_block));
	block->type = BLOCK;
	return ((t_cmdline *) block);
}
