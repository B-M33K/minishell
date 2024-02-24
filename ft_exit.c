/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:34:11 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 17:19:44 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_overlongmin(char *str)
{
	if (ft_strlen(str) >= 20
		&& ft_strncmp(str, "-9223372036854775808", 20) > 0)
		return (1);
	return (0);
}

int	ft_overlongmax(char *str)
{
	if (ft_strlen(str)
		&& ft_strncmp(str, "9223372036854775807", 19) > 0)
		return (1);
	return (0);
}

int	ft_is_numeric(char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_numerate(char *str)
{
	if (ft_overlongmax(str) || ft_overlongmin(str))
	{
		ft_putendl_fd("exit", 1);
		ft_panic("exit", "numeric argument required", 255);
		exit(g_.ext);
	}
	else
	{
		g_.ext = ft_atoi(str);
		ft_putendl_fd("exit", 1);
	}
}

void	ft_exit(char **args)
{
	int		i;

	i = 1;
	while (*(args + i))
	{
		if (i > 1)
		{
			ft_panic("exit", "too many arguments", 1);
			return ;
		}
		if (!ft_is_numeric(*(args + 1)))
		{
			ft_putendl_fd("exit", 1);
			ft_panic("exit", "numeric argument required", 255);
			exit(g_.ext);
		}
		else
			ft_numerate(*(args + 1));
		i++;
	}
	exit (g_.ext);
}
