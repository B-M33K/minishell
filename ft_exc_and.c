/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:34:50 by obahi             #+#    #+#             */
/*   Updated: 2023/08/07 15:24:13 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_and(t_cmdline *cmdline, char **env)
{
	t_and	*and;

	and = (t_and *)cmdline;
	ft_exc_cmdline(and->left, env);
	if (g_exit == 0)
		ft_exc_cmdline(and->right, env);
}
