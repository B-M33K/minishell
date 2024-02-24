/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:33:29 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 11:23:33 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **args)
{
	int		i;
	char	*name;
	char	*value;

	(void)args;
	i = 0;
	while (*(g_.environ + i))
	{
		name = ft_get_name(*(g_.environ + i));
		value = ft_get_value(*(g_.environ + i));
		if (value)
		{
			ft_putstr_fd(name, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(value, 1);
			ft_free(&value);
		}
		ft_free(&name);
		i++;
	}
	g_.ext = 0;
}
