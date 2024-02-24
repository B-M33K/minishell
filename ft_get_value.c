/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:55:27 by obahi             #+#    #+#             */
/*   Updated: 2023/08/24 03:12:28 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value(char *var)
{
	char	*value[5];

	if (!var)
		return (0);
	ft_memset(value, 0, sizeof(value));
	value[1] = ft_get_name(var);
	value[4] = ft_strchr(var, '=');
	if (value[4] == 0)
		return (ft_free(&value[1]), NULL);
	else if (*(value[4] - 1) == '+')
	{
		value[3] = ft_strdup(value[4] + 1);
		value[2] = ft_getenv(value[1]);
		if (!value[2])
			value[2] = ft_strdup("");
		value[0] = ft_strjoin(value[2], value[3]);
		ft_free(&value[2]);
		ft_free(&value[3]);
	}
	else
		value[0] = ft_strdup(value[4] + 1);
	ft_free(&value[1]);
	return (value[0]);
}
