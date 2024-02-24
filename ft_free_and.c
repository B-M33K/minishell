/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:47:21 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:41:13 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_and(t_cmdline *cmdline)
{
	t_and	*and;

	and = (t_and *)cmdline;
	if (and)
	{
		ft_free_cmdline(and->left);
		ft_free_cmdline(and->right);
		free(and);
	}
}
