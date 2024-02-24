/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:25:18 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 15:03:02 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_n(char *str)
{
	if (*str == '-')
	{
		str++;
		if (!*str)
			return (0);
		while (*str && *str == 'n')
			str++;
		return (*str == 0);
	}
	else
		return (0);
}

void	ft_echo(char **args)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	while (*(args + i) && ft_is_n(*(args + i)))
	{
		n = 0;
		i++;
	}
	while (*(args + i))
	{
		ft_putstr_fd(*(args + i), 1);
		if (*(args + i + 1))
			write(1, " ", 1);
		i++;
	}
	if (n)
		write(1, "\n", 1);
	g_.ext = 0;
}
