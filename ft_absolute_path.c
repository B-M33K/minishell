/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:09:00 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 16:22:24 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_directory(char *path)
{
	int			ret;
	struct stat	path_stat;

	ret = 0;
	if (stat(path, &path_stat) == 0)
	{
		if (S_ISDIR(path_stat.st_mode))
			ret = 1;
	}
	return (ret);
}

char	*ft_already_absolurte_path(char *cmd)
{
	char	*abs_path;

	abs_path = 0;
	if (ft_is_directory(cmd))
		ft_panic(cmd, "is a directory", 126);
	else if (!access(cmd, F_OK))
	{
		if (!access(cmd, X_OK))
			abs_path = ft_strdup(cmd);
		else
			ft_panic(cmd, "Permission denied", 126);
	}
	else
		ft_panic(cmd, "No such file or directory", 127);
	return (abs_path);
}

char	*ft_find_absolute_path(char **splitted_path, char *cmd)
{
	char	*ccmd;
	char	*tmp;
	int		i;

	if (!*cmd)
		return (ft_panic(cmd, "command not found", 127), NULL);
	ccmd = ft_strjoin("/", cmd);
	i = -1;
	while (*(splitted_path + (++i)))
	{
		tmp = ft_strjoin(*(splitted_path + i), ccmd);
		if (!access(tmp, F_OK))
		{
			if (!access(tmp, X_OK))
				return (ft_free(&ccmd), tmp);
			else
				return (ft_free(&tmp), ft_free(&ccmd),
					ft_panic(cmd, "Permission denied", 126), NULL);
		}
		ft_free(&tmp);
	}
	return (ft_free(&ccmd),
		ft_panic(cmd, "command not found", 127), NULL);
}

char	*ft_absolute_path(char *cmd)
{
	char	*tmp;
	char	**splitted_path;

	if (!cmd)
		return (0);
	if (ft_strchr(cmd, '/'))
		return (ft_already_absolurte_path(cmd));
	else
	{
		splitted_path = ft_split_path();
		if (!splitted_path)
			return (ft_panic(cmd, " No such file or directory", 127), NULL);
		tmp = ft_find_absolute_path(splitted_path, cmd);
		ft_free2(splitted_path);
		return (tmp);
	}
	return (0);
}
