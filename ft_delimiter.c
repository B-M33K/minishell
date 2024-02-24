/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:05:59 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 21:17:22 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_delimiter(char *str)
{
	char	*delimiter;
	int		i;

	delimiter = 0;
	delimiter = ft_strdup("");
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != 34 && *(str + i) != 39)
			delimiter = ft_strappend(delimiter, *(str + i));
		i++;
	}
	return (delimiter);
}
