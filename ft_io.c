/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:03:21 by obahi             #+#    #+#             */
/*   Updated: 2023/08/23 20:42:36 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_io	*ft_io(int type, char *filename, int *he_status)
{
	t_io	*io;

	io = malloc(sizeof(t_io));
	if (!io)
		return (0);
	ft_memset(io, 0, sizeof(t_io));
	io->type = type;
	io->filename = filename;
	io->content = 0;
	if (type == T_LLESS)
	{
		io->content = ft_here_doc(filename, he_status);
		if (!io->content && *he_status < 0)
		{
			ft_free_io(io);
			return (0);
		}
	}
	io->next = 0;
	return (io);
}
