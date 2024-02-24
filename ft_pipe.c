/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:33:44 by obahi             #+#    #+#             */
/*   Updated: 2023/07/19 06:05:39 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_pipe(t_cmdline *left, t_cmdline *right)
{
	t_pipe	*pip;

	pip = malloc(sizeof(t_pipe));
	if (!pip)
		return (0);
	ft_memset(pip, 0, sizeof(t_pipe));
	pip->type = PIPE;
	pip->left = left;
	pip->right = right;
	return ((t_cmdline *)pip);
}
