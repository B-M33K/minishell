/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:31:23 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 07:12:21 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **args)
{
	char	*pwd;

	(void)args;
	pwd = 0;
	pwd = getcwd(0, 0);
	if (!pwd)
	{
		ft_perror("minishell :", 1);
		return ;
	}
	ft_putendl_fd(pwd, 1);
	ft_free(&pwd);
	g_.ext = 0;
}
