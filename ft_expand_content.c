/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:25:49 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 22:21:17 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_line(char *line, int *flag)
{
	int	f;
	int	v;

	f = 0;
	v = 0;
	if (*line == '$')
		v = 1;
	if (ft_strcmp(line, "*") == 0)
	{
		line = ft_expand_wildcard();
		f = 1;
	}
	else if (v == 1)
	{
		line = ft_expand(line);
		if (line)
			f = 1;
		else
			f = 0;
	}
	else
		line = ft_expand(line);
	*flag = f;
	return (line);
}

t_content	*ft_expand_content(t_content *content)
{
	t_content	*expanded_content;
	char		*expand[3];
	int			f;

	expanded_content = 0;
	while (content)
	{
		expand[0] = ft_expand_line(content->line, &f);
		expand[2] = expand[0];
		if (f == 1)
		{
			while (ft_get_token(&expand[0], &expand[1]))
			{
				ft_add_content(&expanded_content, ft_new_content(expand[1]));
				ft_free(&expand[1]);
			}
			ft_free(&expand[1]);
		}
		else
			ft_add_content(&expanded_content, ft_new_content(expand[0]));
		ft_free(&expand[2]);
		content = content->next;
	}
	return (expanded_content);
}
