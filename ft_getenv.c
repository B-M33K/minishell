/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:59:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/22 00:34:45 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *name)
{
	char	*value;
	int		i;

	value = 0;
	if (!name)
		return (0);
	i = ft_name_does_exist(name);
	if (i >= 0)
		value = ft_get_value(g_.environ[i]);
	return (value);
}
