/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:34:11 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:44:19 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	g_exit = 0;
	while (*(args + i))
	{
		j = 0;
		if (i > 1)
		{
			ft_panic("exit", "too many arguments");
			g_exit = 1;
			return;
		}
		while (*(*(args + 1) + j))
		{
			if (ft_isdigit(*(*(args + 1) + j)))
				i++;
			else
			{
				ft_panic("exit", "numeric argument required");
				g_exit = 255;
				exit(g_exit);
			}
			j++;
		}
		g_exit = ft_atoi(*(args + 1));
	}
	exit (g_exit);
}