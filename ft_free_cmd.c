/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:04:53 by obahi             #+#    #+#             */
/*   Updated: 2023/08/12 10:29:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmd(t_cmdline *cmdline)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmdline;
	if (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		if (cmd->path)
			free(cmd->path);
		if (cmd->args)
			ft_free2(cmd->args);
		ft_free_io(cmd->io);
		free(cmd);
	}
}
