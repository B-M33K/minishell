/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_he_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 07:46:36 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:00:54 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_he_expand(char *str)
{
	char	*expand;
	char	*var;
	char	*tmp1;
	char	*tmp2;
	int		i;

	var = 0;
	tmp1 = 0;
	tmp2 = 0;
	i = 0;
	if (!str)
		return (0);
	expand = ft_strdup("");
	while (*(str + i))
	{
		if (*(str + i) == '$' && *(str + i + 1) && !ft_isspace(*(str + i + 1)))
		{
			i++;
			if (ft_strchr("$#*@!-", *(str + i)) || ft_isdigit(*(str + i)))
				i++;
			else if (*(str + i) == '?')
			{
				tmp1 = ft_itoa(g_exit);
				tmp2 = expand;
				expand = ft_strjoin(expand, tmp1);
				ft_free(&tmp1);
				ft_free(&tmp2);
				i++;
			}
			else
			{
				while (ft_isalnum(*(str + i)) || *(str + i) == '_')
					var = ft_strappend(var, *(str + i++));
				tmp1 = getenv(var);
				ft_free(&var);
				var = 0;
				if (tmp1)
				{
					tmp2 = expand;
					expand = ft_strjoin(expand, tmp1);
					// ft_free(&tmp1);
					ft_free(&tmp2);
					
				}
			}
		}
		else
		{
			tmp1 = expand;
			expand = ft_strappend(expand, *(str + i++));
			ft_free(&tmp1);
		}
	}
	return (expand);
}
