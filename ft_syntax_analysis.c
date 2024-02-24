/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 06:52:10 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 12:53:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax_analysis(char *line)
{
	char		*token;
	int			e;
	int			s;
	int			p;
	static int	tr[9][11] = {{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2}, {-1, -1, 4, 8, 7, 6, 3, 3, 3, 3, 2},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2},
	{-1, -1, 4, 8, 7, 6, 5, 5, 5, 5, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2}};

	e = 0;
	p = 0;
	s = ft_get_token(&line, &token);
	if (!s)
		return (ft_free(&token), 0);
	if (s == T_OPRNTHS)
		p++;
	if (s == -1)
		ft_bzero(token, ft_strlen(token));
	while (tr[e][s] != -1 && s > 0)
	{
		e = tr[e][s];
		ft_free(&token);
		s = ft_get_token(&line, &token);
		if (s == -1)
			*token = 0;
		if (s == T_OPRNTHS)
			p++;
		if (s == T_CPRNTHS)
		{
			if (p > 0)
				p--;
			else
				s = -1;
		}
	}
	if (s == 0 && (e == 2 || e == 4) && p == 0)
	{
		ft_free(&token);
		return (1);
	}
	else
	{
		ft_syntax_error(token);
		ft_free(&token);
		g_exit = 258;
		return (0);
	}
}
