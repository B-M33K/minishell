/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exit_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 07:37:03 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 21:28:47 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_exit_status(char **line)
{
	char	*expand;
	char	*str;

	str = *line;
	expand = 0;
	expand = ft_itoa(g_.ext);
	str++;
	*line = str;
	return (expand); 
}
