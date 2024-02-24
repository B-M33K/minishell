/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:19:16 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 14:07:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_parce_and_or(char **line, t_cmdline *cmline, int i)
{
	t_cmdline	*tmp;
	t_cmdline	*cmdline;

	cmdline = 0;
	if (i == T_AND)
	{
		tmp = ft_parce_pipe(line);
		if (!tmp)
			return (0);
		cmdline = ft_and(cmline, tmp);
		if (!cmdline)
			return (0);
	}
	else
	{
		tmp = ft_parce_pipe(line);
		if (!tmp)
			return (0);
		cmdline = ft_or(cmline, tmp);
		if (!cmdline)
			return (0);
	}
	return (cmdline);
}

t_cmdline	*ft_parce_cmdline(char **line)
{
	t_cmdline	*cmdline;
	int			i;

	cmdline = 0;
	cmdline = ft_parce_pipe(line);
	if (!cmdline)
		return (0);
	while (ft_peak(line, "&|") && **line)
	{
		i = ft_get_token(line, 0);
		cmdline = ft_parce_and_or(line, cmdline, i);
		if (!cmdline)
			return (0);
	}
	return (cmdline);
}
