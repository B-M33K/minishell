/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 07:32:31 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 22:57:19 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_quotes(char **line, char c)
{
	char	*str;
	char	*expand;
	char	*tmp;
	char	*tmp1;

	str = *line;
	tmp = 0;
	expand = ft_strdup("");
	while (*str && *str != c)
	{
		if (*str == '$' && c == 34)
			tmp = ft_expand_dollar(&str, 1);
		else
			tmp = ft_strappend(tmp, *str++);
		tmp1 = expand;
		expand = ft_secure_strjoin(expand, tmp);
		ft_free(&tmp);
		ft_free(&tmp1);
	}
	if (*str == c)
		str++;
	*line = str;
	return (expand);
}

char	*ft_expand_(char **line)
{
	char	*str;
	char	*expand;
	char	*tmp;
	char	*tmp1;

	str = *line;
	expand = 0;
	tmp = 0;
	while (*str && *str != 34 && *str != 39)
	{
		if (*str == '$')
			tmp = ft_expand_dollar(&str, 0);
		else
			tmp = ft_strappend(tmp, *str++);
		tmp1 = expand;
		expand = ft_secure_strjoin(expand, tmp);
		if (tmp)
			ft_free(&tmp);
		if (tmp1)
			ft_free(&tmp1);
	}
	*line = str;
	return (expand);
}
