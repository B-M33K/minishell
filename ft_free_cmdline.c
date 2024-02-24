/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmdline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:52:44 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:43:50 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmdline(t_cmdline *cmdline)
{
	if (cmdline)
	{
		if (cmdline->type == AND)
			ft_free_and(cmdline);
		else if (cmdline->type == OR)
			ft_free_or(cmdline);
		else if (cmdline->type == PIPE)
			ft_free_pipe(cmdline);
		else if (cmdline->type == BLOCK)
			ft_free_block(cmdline);
		else
			ft_free_cmd(cmdline);
	}
}
