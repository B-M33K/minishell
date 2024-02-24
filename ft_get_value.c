/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:55:27 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:00:19 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_get_value(const char *var)
{
    char    *value;
    char    *name;
    char    *tmp;
    char    *tmp1;
    char    *eq;

    value = 0;
    name = 0;
    tmp = 0;
    tmp1 = 0;
    if (!var)
        return(0);
    name = ft_get_name(var);
    eq = ft_strchr(var, '=');
    if (eq == 0)
        return (0);
    else if (*(eq - 1) == '+')
    {
		tmp1 = ft_strdup(eq + 1);
        tmp = getenv(name);
        if (!tmp)
			tmp = ft_strdup("");
		value = ft_strjoin(tmp, tmp1);
		ft_free(&tmp1);
	}
    else
        value = ft_strdup(eq + 1);
	ft_free(&name);
    return (value);
}
