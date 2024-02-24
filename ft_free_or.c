/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:46:19 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:45:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_or(t_cmdline *cmdline)
{
	t_or	*or;

	or = (t_or *)cmdline;
	if (or)
	{
		ft_free_cmdline(or->left);
		ft_free_cmdline(or->right);
		free(or);
	}
}
