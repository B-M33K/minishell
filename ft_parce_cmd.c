/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:09:35 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 21:11:13 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect_(char **line, t_io	**c_io, int i, int *h_s)
{
	char	*token;
	t_io	*io;

	ft_get_token(line, &token);
	io = ft_io(i, token, h_s);
	if (io == 0 && *h_s < 0)
		return (0);
	ft_add_io(c_io, io);
	return (1);
}

t_cmdline	*ft_parce_cmd(char	**line)
{
	t_cmdline	*ret;
	t_cmd		*cmd;
	char		*token;
	int			i;
	int			he_status;

	ret = ft_cmd();
	he_status = 0;
	cmd = (t_cmd *)ret;
	while (!ft_peak(line, "&|)") && **line)
	{
		i = ft_get_token(line, &token);
		if (i >= T_LESS && i <= T_GGREAT)
		{
			ft_free(&token);
			if (!ft_redirect_(line, &cmd->io, i, &he_status))
				return (ft_free_cmdline(ret), NULL);
		}
		else
		{
			ft_add_content(&cmd->content, ft_new_content(token));
			ft_free(&token);
		}
	}
	return (ret);
}
