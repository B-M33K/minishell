/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:48:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/23 20:42:59 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtins(char *cmd, void (**builtins)(char **))
{
	*builtins = 0;
	if (cmd && !ft_strchr(cmd, '/'))
	{
		if (!ft_strcmp(cmd, "echo"))
			return (*builtins = &ft_echo, 1);
		if (!ft_strcmp(cmd, "cd"))
			return (*builtins = &ft_cd, 1);
		if (!ft_strcmp(cmd, "pwd"))
			return (*builtins = &ft_pwd, 1);
		if (!ft_strcmp(cmd, "export"))
			return (*builtins = &ft_export, 1);
		if (!ft_strcmp(cmd, "unset"))
			return (*builtins = &ft_unset, 1);
		if (!ft_strcmp(cmd, "env"))
			return (*builtins = &ft_env, 1);
		if (!ft_strcmp(cmd, "exit"))
			return (*builtins = &ft_exit, 1);
		if (!ft_strcmp(cmd, "true"))
			return (*builtins = &ft_true, 1);
		if (!ft_strcmp(cmd, "false"))
			return (*builtins = &ft_false, 1);
	}
	return (0);
}
