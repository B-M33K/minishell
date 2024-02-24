/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:09:35 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 12:53:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_parce_cmd(char	**line)
{
	t_cmdline	*ret;
	t_cmd		*cmd;
	char		*token;
	char		*tmp;
	char		*args;
	t_io		*io;
	int			i;
	int			he_status;

	ret = ft_cmd();
	he_status = 0;
	args = ft_strdup("");
	cmd = (t_cmd *)ret;
	while (!ft_peak(line, "&|)") && **line)
	{
		i = ft_get_token(line, &token);
		if (i >= T_LESS && i <= T_GGREAT)
		{
			ft_free(&token);
			ft_get_token(line, &token);
			io = ft_io(i, token, &he_status);
			if (io == 0 && he_status < 0)
				return (0);
			ft_add_io(&cmd->io, io);
		}
		else
		{
			tmp = args;
			args = ft_strjoin_(args, token, ' ');
			ft_free(&tmp);
			ft_free(&token);
		}
	}
	cmd->cmd = args;
	return (ret);
}
