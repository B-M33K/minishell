/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:53 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 15:55:49 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_null_env(void)
{
	char	*pwd;
	char	*shlvl;

	g_.environ = malloc(1 * sizeof(char *));
	if (!g_.environ)
		return ;
	g_.environ = ft_memset(g_.environ, 0, sizeof(char *));
	*g_.environ = 0;
	pwd = ft_getcwd();
	if (!pwd)
		return ;
	shlvl = ft_itoa(1);
	g_.path = ft_strdup("usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	ft_setenv("PWD", pwd, 1);
	ft_setenv("SHLVL", shlvl, 1);
	ft_setenv("OLDPWD", 0, 1);
	ft_free(&pwd);
	ft_free(&shlvl);
}

void	ft_default_env(char **env)
{
	char		*pwd;
	char		*shlvl;
	char		**tmp;
	static int	i;

	pwd = 0;
	shlvl = 0;
	tmp = 0;
	i = 1;
	if (*env == 0)
		ft_null_env();
	else
	{
		g_.environ = ft_strstrdup(env);
		shlvl = ft_itoa((i + 1) % 1000);
		ft_setenv("SHLVL", shlvl, 1);
		ft_setenv("OLDPWD", 0, 1);
		g_.path = 0;
		ft_free(&shlvl);
	}
}
