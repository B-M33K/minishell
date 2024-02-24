/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:33:39 by obahi             #+#    #+#             */
/*   Updated: 2023/08/08 10:11:42 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_dup(int old_fd, int new_fd)
{
    int ret;

    if (old_fd != new_fd)
    {
        ret = dup2(old_fd, new_fd);
        if (ret == -1)
        {
            perror("minishell :");
            exit(1);
        }
        close(old_fd);
        return (0);
    }
    else
    {
        ret = dup(old_fd);
        if (ret == -1)
        {
            perror("minishell :");
            exit(1);
        }
        return (ret);
    }
}
