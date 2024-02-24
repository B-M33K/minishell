/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 07:15:35 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:59:46 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_parce_or(char **line)
{
	t_cmdline	*cmdline;
	t_cmdline	*cmdline_2;

	cmdline = ft_parce_pipe(line);
	if (!cmdline)
		return (0);
	if (!ft_peak(line, ")&") && ft_peak_2(line, "||") && **line)
	{
		ft_get_token(line, 0);
		cmdline_2 = ft_parce_or(line);
		if (!cmdline_2)
			return (0);
		cmdline = ft_or(cmdline, cmdline_2);
		if (!cmdline)
			return (0);
	}
	return (cmdline);
}
