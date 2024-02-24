/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:57:30 by obahi             #+#    #+#             */
/*   Updated: 2023/08/22 00:22:30 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_or(t_cmdline *cmdline)
{
	t_or	*or;

	or = (t_or *)cmdline;
	ft_exc_cmdline(or->left);
	if (g_.ext != 0)
		ft_exc_cmdline(or->right);
}
