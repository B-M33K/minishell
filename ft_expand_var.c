/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 07:37:55 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 21:26:32 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_expand_var(char **line, int )
// {
// 	char	*str[4];

// 	ft_memset(str, 0, sizeof(str));
// 	str[0] = *line;
// 	while (*str[0] && (ft_isalnum(*str[0]) || *str[0] == '_'))
// 		str[1] = ft_strappend(str[1], *str[0]++);
// 	str[2] = ft_getenv(str[1]);
// 	ft_free(&str[1]);
// 	if (str[2])
// 	{
// 		str[3] = expand;
// 		expand = ft_strjoin(expand, str[2]);
// 		ft_free(&str[2]);
// 		ft_free(&str[3]);
// 	}
// 	else
// 	{
// 		if (!*expand)
// 		{
// 			ft_free(&expand);
// 			expand = 0;
// 		}
// 	}
// 	return (*line = str[0], expand);
// }

char	*ft_expand_var(char **line, int i)
{
	char	*expand;
	char	*str;
	char	*tmp;
	char	*var;

	str = *line;
	expand = 0;
	var = 0;
	while (*str && (ft_isalnum(*str) || *str == '_'))
		var = ft_strappend(var, *str++);
	tmp = ft_getenv(var);
	ft_free(&var);
	if (tmp)
		expand = tmp;
	else
	{
		if (i == 1)
			expand = ft_strdup("");
		else
			expand = 0;
	}
	*line = str;
	return (expand);
}
