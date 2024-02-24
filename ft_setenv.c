/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:34:33 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 18:47:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_setenv(char *name, char *value, int ovrwrt)
{
	int		i;
	char	*var;

	var = 0;
	if (value)
		var = ft_str_join(name, value, '=');
	else
		var = ft_strdup(name);
	i = ft_name_does_exist(name);
	if (i == -1)
		ft_putenv(var);
	else
	{
		if (ovrwrt == 1)
		{
			ft_free(g_.environ + i);
			*(g_.environ + i) = var;
		}
		else
			ft_free(&var);
	}
	return (1);
}
