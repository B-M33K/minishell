/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:00:27 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 00:22:07 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_quoted(char *str)
{
	int		j;
	char	c;
	int		i;

	j = 0;
	c = *(str + j++);
	while (*(str + j) && *(str + j) != c)
		j++;
	if (*(str + j) == c)
	{
		j++;
		i = ft_get_word_(str + j);
		if (i < 0)
			return (-1);
		return (j + i);
	}
	return (-1);
}

int	ft_get_word_(char *str)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (*(str + j) == 39 || *(str + j) == 34)
		return (ft_get_quoted(str + j));
	if (*(str + j) && !ft_strchr("|&<>() ", *(str + j)))
	{
		j++;
		i = ft_get_word_(str + j);
		if (i < 0)
			return (-1);
		return (j + i);
	}
	return (0);
}
