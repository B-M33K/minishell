/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_2_char__.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:56:18 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 11:39:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_lst_2_char__(t_content *content)
{
	char		**array;
	int			size;
	int			i;

	if (!content)
		return (0);
	size = ft_content_size(content);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (0);
	i = 0;
	while (content)
	{
		if (!content->line)
		{
			content = content->next;
			continue ;
		}
		else
			array[i] = ft_strdup(content->line);
		content = content->next;
		i++;
	}
	array[i] = 0;
	return (array);
}
