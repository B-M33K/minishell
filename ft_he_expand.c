/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_he_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:50:26 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 22:57:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_he_expand(char *str)
{
	char	*expand;
	char	*tmp;
	char	*tmp1;

	if (!str)
		return (0);
	tmp = 0;
	expand = ft_strdup("");
	while (*str)
	{
		if (*str == '$')
			tmp = ft_expand_dollar(&str, 1);
		else
			tmp = ft_strappend(tmp, *str++);
		tmp1 = expand;
		expand = ft_secure_strjoin(expand, tmp);
		ft_free(&tmp);
		ft_free(&tmp1);
	}
	return (expand);
}
