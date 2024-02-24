/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 22:11:14 by obahi             #+#    #+#             */
/*   Updated: 2023/08/23 11:50:08 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_declare(char **str)
{
	int		i;
	char	*name;
	char	*value;	

	i = 0;
	while (*(str + i))
	{
		name = ft_get_name(*(str + i));
		value = ft_get_value(*(str + i));
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(name, 1);
		ft_free(&name);
		if (value)
		{
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(value, 1);
			ft_free(&value);
			ft_putstr_fd("\"", 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
