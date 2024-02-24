/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:33:29 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:23:39 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **args)
{
	int     i;
    char    *name;
    char    *value;

	(void)args;
    i = 0;
    while (*(environ + i))
    {
        name = ft_get_name(*(environ + i));
        value = ft_get_value(*(environ + i));
        if (value)
        {
			ft_putstr_fd(name, 1);
			ft_free(&name);
            ft_putstr_fd("=", 1);
            ft_putendl_fd(value, 1);
            ft_free(&value);
        }
        i++;
    }
}
