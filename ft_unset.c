/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:32:55 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 22:26:57 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **args)
{
	int	i;

	i = 1;
	while (*(args + i))
	{
		if (!ft_is_identifier(*(args + i)))
			ft_panic(*(args + i), "not a valid identifier", 1);
		else
		{
			ft_unsetenv(*(args + i));
			g_.ext = 0;
		}
		i++;
	}
}
