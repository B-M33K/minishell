/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:31:25 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 23:11:33 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_combine(char *expand, char *tmp)
{
	char	*tmp1;

	if (!expand && !tmp)
		return (0);
	else if (!expand)
		return (tmp);
	else if (!tmp)
		return (expand);
	else
	{
		tmp1 = ft_strjoin(expand, tmp);
		ft_free(&expand);
		ft_free(&tmp);
		expand = tmp1;
		return (expand);
	}
}

char	*ft_expand(char *str)
{
	char	*expand;
	char	*tmp;
	char	c;

	if (!str)
		return (0);
	expand = 0;
	if (*str == 34 || *str == 39)
	{
		c = *str++;
		expand = ft_expand_quotes(&str, c);
	}
	else
		expand = ft_expand_(&str);
	if (*str)
	{
		tmp = ft_expand(str);
		expand = ft_combine(expand, tmp);
	}
	return (expand);
}
