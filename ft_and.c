/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:38:30 by obahi             #+#    #+#             */
/*   Updated: 2023/07/20 08:06:00 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*ft_and(t_cmdline *left, t_cmdline *right)
{
	t_and	*and;

	and = malloc(sizeof(t_and));
	if (!and)
		return (0);
	ft_memset(and, 0, sizeof(t_and));
	and->type = AND;
	and->left = left;
	and->right = right;
	return ((t_cmdline *)and);
}
