/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_does_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:10:05 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 16:30:04 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_name_does_exist(char *name)
{
	char	*env_name;
	int		i;

	env_name = 0;
	i = 0;
	while (*(g_.environ + i))
	{
		env_name = ft_get_name(*(g_.environ + i));
		if (!ft_strcmp(name, env_name))
		{
			ft_free(&env_name);
			return (i);
		}
		else
			ft_free(&env_name);
		i++;
	}
	return (-1);
}
