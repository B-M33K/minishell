/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:10:11 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 16:09:26 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_home(void)
{
	char	*npc[3];

	npc[2] = 0;
	npc[0] = ft_getenv("HOME");
	if (!npc[0])
	{
		ft_panic("cd", "HOME not set", 1);
		return ;
	}
	npc[1] = ft_getenv("PWD");
	ft_setenv("OLDPWD", npc[1], 1);
	ft_free(&npc[1]);
	if (ft_chdir(npc[0]) == -1)
	{
		ft_free(&npc[0]);
		return ;
	}
	ft_setenv("PWD", npc[0], 1);
	ft_free(&npc[0]);
	g_.ext = 0;
}

void	ft_cd_old(void)
{
	char	*npc[3];

	npc[2] = ft_getenv("PWD");
	npc[0] = ft_getenv("OLDPWD");
	if (!npc[0])
	{
		ft_free(&npc[2]);
		ft_panic("cd", "OLDPWD not set", 1);
		return ;
	}
	npc[1] = ft_getenv("PWD");
	ft_setenv("OLDPWD", npc[1], 1);
	ft_free(&npc[1]);
	if (ft_chdir(npc[0]) == -1)
	{
		ft_free(&npc[2]);
		ft_free(&npc[0]);
		return ;
	}
	ft_setenv("PWD", npc[0], 1);
	ft_putendl_fd(npc[0], 1);
	ft_free(&npc[2]);
	ft_free(&npc[0]);
	g_.ext = 0;
}

void	ft_tmp_free(char **tmp, char **tmp2)
{
	ft_free(tmp);
	ft_free(tmp2);
}

void	ft_cdir(char *str)
{
	char	*npc[3];

	if (*str == '~' || *str == '/' || *str == '.')
		npc[0] = ft_strdup(str);
	else
	{
		npc[2] = ft_getcwd();
		if (npc[2] == 0)
			return ;
		if (*(str + ft_strlen(str) - 1) == '/')
			*(str + ft_strlen(str) - 1) = 0;
		npc[0] = ft_str_join(npc[2], str, '/');
		ft_free(&npc[2]);
	}
	npc[1] = ft_getenv("PWD");
	ft_setenv("OLDPWD", npc[1], 1);
	if (ft_chdir(npc[0]) == -1)
	{
		ft_tmp_free(&npc[0], &npc[1]);
		return ;
	}
	ft_setenv("PWD", npc[0], 1);
	ft_tmp_free(&npc[0], &npc[1]);
	g_.ext = 0;
}

void	ft_cd(char **args)
{
	if (!args[1] || (!ft_strcmp(args[1], "~") || !ft_strcmp(args[1], "--")))
		ft_cd_home();
	else if (!ft_strcmp(args[1], "-"))
		ft_cd_old();
	else
		ft_cdir(args[1]);
}
