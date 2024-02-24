/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:23:20 by obahi             #+#    #+#             */
/*   Updated: 2023/08/06 10:49:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_token(char **line, char **token)
{
	char	*s;
	int		ret;
	int		i;
	int		j;

	s = *line;
	i = 0;
	j = 0;
	while (*(s + i) && ft_isspace(*(s + i)))
		i++;
	if (*(s + i + j) == 0)
		ret = 0;
	else if (*(s + i + j) == '|')
	{
		j++;
		ret = T_PIPE;
		if (*(s + i + j) == '|')
		{
			j++;
			ret = T_OR;
		}
	}
	else if (*(s + i + j) == '&')
	{
		j++;
		ret = T_UNKNOWN;
		if (*(s + i + j) == '&')
		{
			j++;
			ret = T_AND;
		}
	}
	else if (*(s + i + j) == '<')
	{
		j++;
		ret = T_LESS;
		if (*(s + i + j) == '<')
		{
			j++;
			ret = T_LLESS;
		}
	}
	else if (*(s + i + j) == '>')
	{
		j++;
		ret = T_GREAT;
		if (*(s + i + j) == '>')
		{
			j++;
			ret = T_GGREAT;
		}
	}
	else if (*(s + i + j) == '(')
	{
		j++;
		ret = T_OPRNTHS;
	}
	else if (*(s + i + j) == ')')
	{
		j++;
		ret = T_CPRNTHS;
	}
	else if (ft_strchr(SPECIALS, *(s + i + j)))
	{
		j++;
		ret = T_UNKNOWN;
	}
	else
	{
		ret = T_WORD;
		if (ft_get_word(s + i, &j) < 0)
			ret = -1;
	}
	if (token)
		*token = ft_substr(s, i, j);
	*line = s + i + j;
	return (ret);
}

// int main()
// {
// 	char *line;
// 	char *token;
// 	char *tmp;

// 	line = readline("line > ");
// 	tmp = line;
// 	ft_get_token(&line, &token);
// 	printf("token = %s\n", token);
// 	free(token);
// 	free(tmp);
// 	atexit(ft_leaks);
// }
