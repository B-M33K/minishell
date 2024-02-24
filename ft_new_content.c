/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:39:04 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:55:46 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_content	*ft_new_content(char *line)
{
	t_content	*new_content;

	new_content = malloc(sizeof(t_content));
	if (!new_content)
		return (0);
	ft_memset(new_content, 0, sizeof(t_content));
	new_content->line = ft_strdup(line);
	new_content->next = 0;
	return (new_content);
}
