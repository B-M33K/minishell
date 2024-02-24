/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:34:33 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 08:59:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_setenv(const char *name, const char *value, int ovrwrt)
{
    int      i;
    char    *var;
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
            ft_free(environ + i);
            *(environ + i) = var;
        }
    }
    return (1);
}
