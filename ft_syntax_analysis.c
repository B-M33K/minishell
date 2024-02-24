/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 06:52:10 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 20:18:38 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_automate(char *line, char **token, int tr[9][11], int esp[3])
{
	esp[1] = ft_get_token(&line, token);
	if (esp[1] == 0)
		return (ft_free(token), 0);
	if (esp[1] == T_OPRNTHS)
		esp[2]++;
	if (esp[1] == -1)
		ft_bzero(*token, ft_strlen(*token));
	while (tr[esp[0]][esp[1]] >= 0 && esp[1] > 0)
	{
		esp[0] = tr[esp[0]][esp[1]];
		ft_free(token);
		esp[1] = ft_get_token(&line, token);
		if (esp[1] == -1)
			ft_bzero(*token, ft_strlen(*token));
		if (esp[1] == T_OPRNTHS)
			esp[2]++;
		if (esp[1] == T_CPRNTHS)
		{
			if (esp[2] > 0)
				esp[2]--;
			else
				esp[1] = -1;
		}
	}
	return (1);
}

int	ft_check_finalstate(char *token, int esp[3])
{
	if (esp[1] == 0 && (esp[0] == 2 || esp[0] == 4) && esp[2] == 0)
	{
		ft_free(&token);
		return (1);
	}
	else
	{
		ft_syntax_error(token);
		ft_free(&token);
		g_.ext = 258;
		return (0);
	}
}

int	ft_syntax_analysis(char *line)
{
	char		*token;
	int			esp[3];
	static int	tr[9][11] = {{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2}, {-1, -1, 4, 8, 7, 6, 3, 3, 3, 3, 2},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2},
	{-1, -1, 4, 8, 7, 6, 5, 5, 5, 5, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2},
	{-1, 1, -1, -1, -1, -1, 3, 3, 3, 3, 2}};

	ft_memset(esp, 0, sizeof(esp));
	if (ft_automate(line, &token, tr, esp) == 0)
		return (0);
	return (ft_check_finalstate(token, esp));
}
