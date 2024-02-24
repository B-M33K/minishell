/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:57:30 by obahi             #+#    #+#             */
/*   Updated: 2023/08/13 11:36:14 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_or(t_cmdline *cmdline, char **env)
{
	t_or	*or;

	or = (t_or *)cmdline;
	ft_exc_cmdline(or->left, env);
	if (g_exit != 0)
		ft_exc_cmdline(or->right, env);
}
