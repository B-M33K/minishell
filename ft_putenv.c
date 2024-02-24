/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:43:17 by obahi             #+#    #+#             */
/*   Updated: 2023/08/23 20:47:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putenv(char *string)
{
	int		i;
	int		len;
	char	**tmp;

	tmp = 0;
	len = ft_strstrlen(g_.environ);
	tmp = malloc((len + 2) * sizeof(char *));
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, (len + 2));
	i = 0;
	while (*(g_.environ + i))
	{
		*(tmp + i) = ft_strdup(*(g_.environ + i));
		i++;
	}
	*(tmp + i++) = string;
	*(tmp + i) = 0;
	ft_free2(g_.environ);
	g_.environ = tmp;
	return (1);
}
