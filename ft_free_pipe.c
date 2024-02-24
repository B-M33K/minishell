/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:47:55 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:46:06 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_pipe(t_cmdline *cmdline)
{
	t_pipe	*pip;

	pip = (t_pipe *)cmdline;
	if (pip)
	{
		ft_free_cmdline(pip->left);
		ft_free_cmdline(pip->right);
		free(pip);
	}
}
