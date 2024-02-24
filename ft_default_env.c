/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:53 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:47:53 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_default_env(void){
    char		*pwd;
    char		*shlvl;
	char		**tmp;
	static int	i;

	pwd = 0;
	shlvl = 0;
	tmp = 0;
	i = 1;
    if (*environ == 0)
    {
		tmp = malloc(1 * sizeof(char *));
		if (!tmp)
			return;
		tmp = ft_memset(tmp, 0, sizeof(char *));
		*tmp = 0;
		environ = tmp;
		pwd = getcwd(0, 0);
		shlvl = ft_itoa(1);
        ft_setenv("PWD", pwd, 0);
		ft_setenv("SHLVL", shlvl, 0);
		ft_setenv("OLDPWD", 0, 0);
		ft_free(&pwd);
		ft_free(&shlvl);
    }
	else
	{
		tmp = ft_strstrdup(environ);
		environ = tmp;
		shlvl = ft_itoa((i + 1) % 1000);
		ft_setenv("SHLVL", shlvl, 1);
		ft_free(&shlvl);
	}
}
