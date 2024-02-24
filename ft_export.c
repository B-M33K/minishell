/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:32:22 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 22:27:58 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_var(char *str)
{
	char	*name;
	char	*value;

	name = ft_get_name(str);
	if (name)
	{
		value = ft_get_value(str);
		if (value)
		{
			ft_setenv(name, value, 1);
			ft_free(&value);
		}
		else
			ft_setenv(name, value, 0);
		ft_free(&name);
		g_.ext = 0;
	}
}

void	ft_export(char **args)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = 0;
	while (*(args + (++i)))
		ft_export_var(*(args + i));
	if (i == 1)
	{
		tmp = ft_sort_env();
		ft_declare(tmp);
		ft_free2(tmp);
		g_.ext = 0;
	}
}
