/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:33:38 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 11:00:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_parce_pipe(char **line)
{
	t_cmdline	*cmdline_2;
	t_cmdline	*cmdline;

	cmdline = ft_parce_block(line);
	if (!cmdline)
		return (0);
	if (!ft_peak(line, ")&") && !ft_peak_2(line, "||") && ft_peak(line, "|") && **line)
	{
		ft_get_token(line, 0);
		cmdline_2 = ft_parce_pipe(line);
		if (!cmdline_2)
			return (0);
		cmdline = ft_pipe(cmdline, cmdline_2);
	}
	return (cmdline);
}
