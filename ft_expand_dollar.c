/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:48:51 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 22:59:27 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_dollar(char **s, int i)
{
	char	*tmp;
	char	*str;

	tmp = 0;
	str = *s;
	str++;
	if (!*str || ft_isspace(*str) || *str == 34)
		tmp = ft_strappend(tmp, '$');
	else if (ft_strchr("$#*@!-", *str) || ft_isdigit(*str))
		str++;
	else if (*str == '?')
		tmp = ft_expand_exit_status(&str);
	else
		tmp = ft_expand_var(&str, i);
	*s = str;
	return (tmp);
}
