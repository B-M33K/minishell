/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:10:11 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 22:27:07 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_pwd(char *str1)
{
	char	cwd[1024];
	// char	*str;

	if (!str1)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
        {
            perror("minishell :");
            return ;
        }
		ft_setenv("OLDPWD", cwd, 1);
		// str = ft_strjoin("OLDPWD=", cwd);
		// ft_export(str);
		// ft_free(&str);
	}
	else
	{
		ft_setenv("PWD", str1, 1);
		// str = ft_strjoin("PWD=", str1);
		// ft_export(str);
	}
}

// void ft_cd(char **argv)
// {

// }