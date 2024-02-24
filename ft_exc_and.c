/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:34:50 by obahi             #+#    #+#             */
/*   Updated: 2023/08/22 00:21:24 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_and(t_cmdline *cmdline)
{
	t_and	*and;

	and = (t_and *)cmdline;
	ft_exc_cmdline(and->left);
	if (g_.ext == 0)
		ft_exc_cmdline(and->right);
}
