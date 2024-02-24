/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:40:06 by obahi             #+#    #+#             */
/*   Updated: 2023/07/20 08:11:48 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_or(t_cmdline *left, t_cmdline *right)
{
	t_or	*or;

	or = malloc(sizeof(t_or));
	if (!or)
		return (0);
	ft_memset(or, 0, sizeof(or));
	or->type = OR;
	or->left = left;
	or->right = right;
	return ((t_cmdline *)or);
}
