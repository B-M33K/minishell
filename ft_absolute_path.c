/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:09:00 by obahi             #+#    #+#             */
/*   Updated: 2023/08/07 15:03:06 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_absolute_path(char *cmd)
{
	char	*tmp;
	char	*ccmd;
	char	**splitted_path;
	int		i;

	if (!cmd)
		return (0);
	if (ft_strchr(cmd, '/'))
	{
		if (!access(cmd, F_OK))
		{
			if (!access(cmd, X_OK))
				return (ft_strdup(cmd));
			else
			{
				ft_panic(cmd, "Permission denied");
				g_exit = 126;
				return (0);
			}
		}
		else
		{
			ft_panic(cmd, "No such file or directory");
			g_exit = 127;
			return (0);
		}
	}
	else
	{
		splitted_path = ft_split_path();
		if (!splitted_path)
			return (0);
		ccmd = ft_strjoin("/", cmd);
		i = 0;
		while (*(splitted_path + i))
		{
			tmp = ft_strjoin(*(splitted_path + i), ccmd);
			if (!access(tmp, F_OK))
			{
				if (!access(tmp, X_OK))
				{
					free(ccmd);
					ccmd = 0;
					ft_free2(splitted_path);
					splitted_path = 0;
					return (tmp);
				}
				else
				{
					ft_panic(cmd, "Permission denied");
					g_exit = 126;
					return (0);
				}
			}
			free(tmp);
			tmp = 0;
			i++;
		}
		ft_panic(cmd, "command not found");
		g_exit = 127;
		free(ccmd);
		ccmd = 0;
		ft_free2(splitted_path);
		splitted_path = 0;
		return (0);
	}
	return (0);
}
