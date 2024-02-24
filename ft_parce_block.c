/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:41:45 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 12:53:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_parce_block(char **line)
{
	t_cmdline	*cmdline;
	t_block		*block;
	int			i;
	char		*token;
	t_io		*io;
	int			he_status;

	he_status = 0;
	cmdline = ft_block();
	if (!cmdline)
		return (0);
	block = (t_block *)cmdline;
	if (ft_peak(line, "("))
	{
		ft_get_token(line, 0);
		block->cmdline = ft_parce_cmdline(line);
		if (!block->cmdline)
			return (0);
		ft_get_token(line, 0);
		while (ft_peak(line, "><") && **line)
		{
			i = ft_get_token(line, 0);
			ft_free(&token);
			ft_get_token(line, &token);
			io = ft_io(i, token, &he_status);
			if (io == 0 && he_status < 0)
				return (0);
			ft_add_io(&block->io, io);
		}
		return (cmdline);
	}
	else
	{
		ft_free_cmdline(cmdline);
		cmdline = ft_parce_cmd(line);
		if (!cmdline)
			return (0);
	}
	return (cmdline);
}
