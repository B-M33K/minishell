/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:32:22 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:12:44 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char **args)
{
	int		i;
	char	*name;
	char	*value;
	char	**tmp;

	i = 1;
	name = 0;
	value = 0;
	tmp = 0;
	while (*(args + i))
	{
		name = ft_get_name(*(args + i));
		if (name)
		{
			value = ft_get_value(*(args + i));
			if (value)
			{
				ft_setenv(name, value, 1);
				ft_free(&value);
			}
			else
				ft_setenv(name, value, 0);
			ft_free(&name);
		}
		i++;
	}
	if (i == 1)
	{
		tmp = ft_sort_environ();
		ft_declare(tmp);
		ft_free2(tmp);
	}
}