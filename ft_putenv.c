/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:43:17 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 09:36:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_putenv(const char *string)
{
    int     i;
    int     len;
    char    **tmp;

    tmp = 0;
    len = ft_strstrlen(environ);
    tmp = malloc((len + 2) * sizeof(char *));
    if (!tmp)
        return (0);
    ft_memset(tmp, 0, (len + 2));
    i = 0;
    while (*(environ + i))
    {
        *(tmp + i) = ft_strdup(*(environ + i));
        i++;
    }
    *(tmp + i++) = (char *)string;
    *(tmp + i) = 0;
    ft_free2(environ);
    environ = tmp;
    return (1);
}
