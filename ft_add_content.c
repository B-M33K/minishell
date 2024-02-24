/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:37:43 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 10:17:14 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_content(t_content **content, t_content *new_content)
{
	t_content	*head;

	head = *content;
	if (head == 0)
		*content = new_content;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_content;
	}
}
