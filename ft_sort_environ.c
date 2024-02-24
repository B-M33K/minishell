/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 22:22:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/19 22:40:08 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_swap(char **a, char **b)
{
    char    *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

char    **ft_sort_environ(void)
{
    char    **tmp;
    int     env_len;
    int     i;
    int     j;

    tmp = ft_strstrdup(environ);
    env_len = ft_strstrlen(tmp);
    i = 0;
    while (i < env_len - 1)
    {
        j = 0;
        while (j < env_len - i - 1)
        {
            if (ft_strcmp(*(tmp + j), *(tmp + j + 1)) > 0)
                ft_swap(tmp + j, tmp + j + 1);
            j++;
        }
        i++;
    }
    return (tmp);
}
