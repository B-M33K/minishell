/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:49:44 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 02:29:44 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_name(char *var)
{
	char	*name;
	char	*eq;
	int		name_len;

	name_len = 0;
	name = 0;
	if (!var)
		return (0);
	eq = ft_strchr(var, '=');
	if (eq == 0)
		name = ft_strdup(var);
	else if (eq == var)
		name = ft_strdup(var);
	else
	{
		name_len = eq - var;
		(*(eq - 1) == '+') && name_len--;
		name = ft_substr(var, 0, name_len);
	}
	if (ft_is_identifier(name) == 0)
	{
		ft_panic(name, "not a valid identifier", 1);
		ft_free(&name);
	}
	return (name);
}
