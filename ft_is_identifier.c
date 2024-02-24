/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:10:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/17 11:14:05 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_is_identifier(char *str)
{
    int i;

    i = 0;
    if (ft_isdigit(*(str)))
        return (0);
    else
    {
        while (*(str + i) && (ft_isalnum(*(str + i)) || *(str + i) == '_'))
            i++;
        if(*(str + i) == 0)
            return (1);
        else
            return (0);
    }
    return (0);
}
