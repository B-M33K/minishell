/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:52:23 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 19:52:35 by obahi            ###   ########.fr       */
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
		1 && (c = *(s + j)) && (j++);
		while (*(s + j) && *(s + j) != c)
			1 && (j++) && (*jj = j);
		if (*(s + j) == c)
		{
			1 && (j++) && (*jj = j);
			return (ft_get_word(s, jj));
		}
		return (-1);
	}
	else
	{
		if (*(s + j) && !ft_strchr("|&<>() ", *(s + j)))
		{
			1 && (j++) && (*jj = j);
			return (ft_get_word(s, jj));
		}
		return (0);
	}
}
