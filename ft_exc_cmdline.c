/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cmdline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:57:44 by obahi             #+#    #+#             */
/*   Updated: 2023/08/22 00:22:16 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_cmdline(t_cmdline *cmdline)
{
	if (cmdline->type == CMD)
		ft_exc_cmd(cmdline);
	else if (cmdline->type == PIPE)
		ft_exc_pipe(cmdline);
	else if (cmdline->type == AND)
		ft_exc_and(cmdline);
	else if (cmdline->type == OR)
		ft_exc_or(cmdline);
	else
		ft_exc_block(cmdline);
}
