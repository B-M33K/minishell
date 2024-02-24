/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:19:19 by obahi             #+#    #+#             */
/*   Updated: 2023/08/05 08:31:19 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_path(void)
{
	char	*path_var;
	char	**path;

	path_var = 0;
	path_var = getenv("PATH");
	path = ft_split(path_var, ':');
	return (path);
}
