/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:46:10 by obahi             #+#    #+#             */
/*   Updated: 2023/08/12 09:01:44 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execve(const char *pathname, char *const argv[], char *const envp[])
{
	int	ret;

	ret = execve(pathname, argv, envp);
	if (ret == -1)
	{
		perror("minishell : ");
		exit(1);
	}
	return (0);
}
