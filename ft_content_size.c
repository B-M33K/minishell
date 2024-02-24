/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:50:51 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 12:41:39 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_content_size(t_content *content)
{
	int	size;

	size = 0;
	while (content)
	{
		if (!content->line)
		{
			content = content->next;
			continue ;
		}
		size++;
		content = content->next;
	}
	return (size);
}
