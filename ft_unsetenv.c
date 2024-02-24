/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:35:51 by obahi             #+#    #+#             */
/*   Updated: 2023/08/23 20:54:53 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unsetenv(char *name)
{
	char	*tmp;
	int		i;

	i = ft_name_does_exist(name);
	if (i >= 0)
	{
		tmp = *(g_.environ + i);
		while (*(g_.environ + i))
		{
			*(g_.environ + i) = *(g_.environ + i + 1);
			i++;
		}
		ft_free(g_.environ + i);
		ft_free(&tmp);
	}
	return (0);
}
