/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:48:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 22:28:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtins(char *cmd, void (**builtins)(char **))
{
	int	len;

	*builtins = 0;
	if (cmd && !ft_strchr(cmd, '/'))
	{
		len = ft_strlen(cmd);
		if (len == 4 && !ft_strncmp(cmd, "echo", len))
			return (*builtins = &ft_echo,1);
		// if (len == 2 && !ft_strncmp(cmd, "cd", len))
		// 	return (*builtins = &ft_cd,1);
		if (len == 3 && !ft_strncmp(cmd, "pwd", len))
			return (*builtins = &ft_pwd,1);
		if (len == 6 && !ft_strncmp(cmd, "export", 2))
			return (*builtins = &ft_export,1);
		if (len == 5 && !ft_strncmp(cmd, "unset", 2))
			return (*builtins = &ft_unset,1);
		if (len == 3 && !ft_strncmp(cmd, "env", 2))
			return (*builtins = &ft_env,1);
		if (len == 4 && !ft_strncmp(cmd, "exit", 2))
			return (*builtins = &ft_exit,1);
		if (len == 4 && !ft_strncmp(cmd, "true", 2))
			return (*builtins = &ft_true,1);
		if (len == 5 && !ft_strncmp(cmd, "false", 2))
			return (*builtins = &ft_false,1);
	}
	return (0);
}