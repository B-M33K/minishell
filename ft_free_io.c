/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:20:03 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 09:17:58 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_io(t_io *io)
{
	t_io	*tmp;

	while (io)
	{
		tmp = io;
		io = io->next;
		ft_free(&tmp->filename);
		if (tmp->content)
			ft_free_content(tmp->content);
		free(tmp);
	}
}
