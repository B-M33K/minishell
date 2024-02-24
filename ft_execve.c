/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:46:10 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 16:11:11 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execve(char *pathname, char **argv)
{
	int	ret;

	ret = execve(pathname, argv, g_.environ);
	if (ret == -1)
	{
		ft_perror("minishell : ", 1);
		exit(1);
	}
	return (0);
}
