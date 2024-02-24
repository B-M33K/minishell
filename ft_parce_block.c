/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:41:45 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 13:41:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_inside_block(char **line, t_cmdline **b_cmdline, t_io **b_io, int *h_s)
{
	char	*token;
	t_io	*io;
	int		i;

	ft_get_token(line, 0);
	*b_cmdline = ft_parce_cmdline(line);
	if (!*b_cmdline)
		return (0);
	ft_get_token(line, 0);
	while (ft_peak(line, "><") && **line)
	{
		i = ft_get_token(line, 0);
		ft_get_token(line, &token);
		io = ft_io(i, token, h_s);
		if (io == 0 && *h_s < 0)
			return (0);
		ft_add_io(b_io, io);
	}
	return (1);
}

t_cmdline	*ft_parce_block(char **line)
{
	t_cmdline	*cmdline;
	t_block		*block;
	int			he_status;

	he_status = 0;
	cmdline = ft_block();
	if (!cmdline)
		return (0);
	block = (t_block *)cmdline;
	if (ft_peak(line, "("))
	{
		if (!ft_inside_block(line, &block->cmdline, &block->io, &he_status))
			return (0);
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
