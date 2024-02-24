/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peak_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:57:23 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 11:00:51 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_peak_2(char **line, char *toks)
{
	char	*s;
	int		n;

	n = ft_strlen(toks);
	s = *line;
	while (*s && ft_isspace(*s))
		s++;
	*line = s;
	return (*line && !ft_strncmp(s, toks, n));
}
