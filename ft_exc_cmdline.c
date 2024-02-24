/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cmdline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:57:44 by obahi             #+#    #+#             */
/*   Updated: 2023/08/07 13:48:14 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_cmdline(t_cmdline *cmdline, char **env)
{
	if (cmdline->type == CMD)
		ft_exc_cmd(cmdline, env);
	else if (cmdline->type == PIPE)
		ft_exc_pipe(cmdline, env);
	else if (cmdline->type == AND)
		ft_exc_and(cmdline, env);
	else if (cmdline->type == OR)
		ft_exc_or(cmdline, env);
	else
		ft_exc_block(cmdline, env);
}
