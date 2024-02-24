/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:59:42 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 12:53:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strappend(char *str, char c)
{
	char	*tmp;
	int		size;
	int		i;

	tmp = 0;
	if (!str)
	{
		tmp = malloc(2);
		if (!tmp)
			return (0);
		*tmp = c;
		*(tmp + 1) = 0;
	}
	else
	{
		i = 0;
		size = ft_strlen(str) + 2;
		tmp = malloc(size);
		if (!tmp)
			return (0);
		while (*(str + i))
		{
			*(tmp + i) = *(str + i);
			i++;
		}
		*(tmp + i) = c;
		*(tmp + i + 1) = 0;
	}
	ft_free(&str);
	return (tmp);
}
