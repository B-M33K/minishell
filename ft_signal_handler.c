/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:04:53 by obahi             #+#    #+#             */
/*   Updated: 2023/08/24 20:36:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint_handler(int sig)
{
	if (sig == SIGINT)
		close(0);
}

void	ft_heredoc_sigint(int sig)
{
	if (sig == SIGINT)
		close(0);
}
