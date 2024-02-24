/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:31:25 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 13:00:31 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_var(char *str, int expnd_wc)
{
	char	*expand;
	char	*var;
	char	*tmp1;
	char	*tmp2;
	char	c;
	int		i;

	i = 0;
	var = 0;
	tmp1 = 0;
	tmp2 = 0;
	if (!str)
		return (0);
	expand = ft_strdup("");
	if (*str == 34 || *str == 39)
	{
		c = *str;
		i++;
		while (*(str + i) && *(str + i) != c)
		{
			if (*(str + i) == '$' && *(str + i + 1) && !ft_isspace(*(str + i + 1)) && c == 34)
			{
				i++;
				if (ft_strchr("$#*@!-", *(str + i)) || ft_isdigit(*(str + i)))
					i++;
				else if (*(str + i) == '?')
				{
					tmp1 = ft_itoa(g_exit);
					tmp2 = expand;
					expand = ft_strjoin(expand, tmp1);
					// ft_free(&tmp1);
					ft_free(&tmp2);
					i++;
				}
				else
				{
					while (ft_isalnum(*(str + i)) || *(str + i) == '_')
						var = ft_strappend(var, *(str + i++));
					tmp1 = getenv(var);
					ft_free(&var);
					if (tmp1)
					{
						tmp2 = expand;
						expand = ft_strjoin(expand, tmp1);
						ft_free(&tmp2); 
					}
				}
			}
			else
				expand = ft_strappend(expand, *(str + i++));
		}
		if (*(str + i))
			i++;
	}
	else
	{
		while (*(str + i) && *(str + i) != 34 && *(str + i) != 39 )
		{
			if (*(str + i) == '*')
			{
				tmp1 = expand;
				if (expnd_wc)
				{
					tmp2 = ft_expand_wildcard();
					expand = ft_strjoin(expand, tmp2);
					ft_free(&tmp2);			
				}
				else
					expand = ft_strjoin(expand, "*");
				ft_free(&tmp1);
				i++;
			} 
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
				expand = ft_strappend(expand, *(str + i++));
		}
	}
	if (*(str + i))
	{
		tmp1 = expand;
		expand = ft_strjoin(expand, ft_expand_var(str + i, expnd_wc));
		ft_free(&tmp1);
	}
	return (expand);
}
