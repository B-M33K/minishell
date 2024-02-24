/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:17:24 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:49:47 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_word(char *s, int *jj)
{
	int		j;
	char	c;

	j = *jj;
	if (*(s + j) == 39 || *(s + j) == 34)
	{
		c = *(s + j);
		j++;
		while (*(s + j) && *(s + j) != c)
			j++;
		*jj = j;
		if (*(s + j) == c)
		{
			j++;
			*jj = j;
			return (ft_get_word(s, jj));
		}
		else
			return (-1);
	}
	else
	{
		if (*(s + j) && !ft_strchr("|&<>() ", *(s + j)))
		{
			j++;
			*jj = j;
			return (ft_get_word(s, jj));
		}
		else
			return (0);
	}
	return (0);
}
