/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:00:49 by obahi             #+#    #+#             */
/*   Updated: 2023/08/12 10:03:00 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_io(t_io **io, t_io *new_io)
{
	t_io	*head;

	head = *io;
	if (head == 0)
		*io = new_io;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_io;
	}
}
