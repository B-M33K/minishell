/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:49:38 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 07:12:11 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open(char *pathname, int flags, mode_t mode)
{
	int	fd;

	fd = open(pathname, flags, mode);
	if (fd == -1)
	{
		if (errno == EACCES)
			ft_panic((char *)pathname, "Permission denied", 1);
		else if (errno == ENOENT)
			ft_panic((char *)pathname, "No such file or directory", 1);
		else
			ft_perror("minishell :", 1);
	}
	return (fd);
}
