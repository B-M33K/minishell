/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:40:39 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:44:18 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_content(t_content *content)
{
	t_content	*tmp;

	while (content)
	{
		tmp = content;
		content = content->next;
		free(tmp->line);
		free(tmp);
	}
}
