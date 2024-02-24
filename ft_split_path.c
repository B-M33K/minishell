/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:19:19 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 13:30:32 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_path(void)
{
	char	*path_var;
	char	**path;

	path_var = 0;
	path = 0;
	path_var = ft_getenv("PATH");
	if (!path_var)
	{
		if (g_.path)
			path = ft_split(g_.path, ':');
	}
	else
		path = ft_split(path_var, ':');
	return (path);
}
