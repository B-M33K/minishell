/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:03:47 by obahi             #+#    #+#             */
/*   Updated: 2023/08/23 11:26:56 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_panic(char *key_word, char *error_msg, int ext)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(key_word, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_msg, 2);
	g_.ext = ext;
}
