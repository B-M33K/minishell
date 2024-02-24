/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:23:20 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 02:34:23 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe_and_or(char *str, int *jj)
{
	int	ret;
	int	j;

	j = *jj;
	if (*(str + j) == '|')
	{
		j++;
		ret = T_PIPE;
		if (*(str + j) == '|')
		{
			j++;
			ret = T_OR;
		}
	}
	else
	{
		j++;
		ret = T_UNKNOWN;
		if (*(str + j) == '&')
		{
			j++;
			ret = T_AND;
		}
	}
	return (*jj = j, ret);
}

int	ft_redirect(char *str, int *jj)
{
	int	ret;
	int	j;

	j = *jj;
	if (*(str + j) == '<')
	{
		j++;
		ret = T_LESS;
		if (*(str + j) == '<')
		{
			j++;
			ret = T_LLESS;
		}
	}
	else
	{
		j++;
		ret = T_GREAT;
		if (*(str + j) == '>')
		{
			j++;
			ret = T_GGREAT;
		}
	}
	return (*jj = j, ret);
}

int	ft_paranthesises(char *str, int *jj)
{
	int	j;
	int	ret;

	j = *jj;
	if (*(str + j) == '(')
	{
		j++;
		ret = T_OPRNTHS;
	}
	else
	{
		j++;
		ret = T_CPRNTHS;
	}
	*jj = j;
	return (ret);
}

int	ft_tokenizer(char *str, int *jj)
{
	int	ret;
	int	j;

	j = *jj;
	if (*(str + j) == 0)
		ret = 0;
	else if (*(str + j) == '|' || *(str + j) == '&')
		ret = ft_pipe_and_or(str, &j);
	else if (*(str + j) == '<' || *(str + j) == '>')
		ret = ft_redirect(str, &j);
	else if (*(str + j) == '(' || *(str + j) == ')')
		ret = ft_paranthesises(str, &j);
	else if (ft_strchr(SPECIALS, *(str + j)))
	{
		j++;
		ret = T_UNKNOWN;
	}
	else
	{
		ret = T_WORD;
		j = ft_get_word_(str);
		if (j < 0)
			ret = -1;
	}
	return (*jj = j, ret);
}

int	ft_get_token(char **line, char **token)
{
	char	*s;
	int		ret;
	int		i;
	int		j;

	s = *line;
	i = 0;
	j = 0;
	if (!*line)
	{
		*token = 0;
		return (0);
	}
	while (*(s + i) && ft_isspace(*(s + i)))
		i++;
	ret = ft_tokenizer(s + i, &j);
	if (token)
		*token = ft_substr(s, i, j);
	*line = s + i + j;
	return (ret);
}
