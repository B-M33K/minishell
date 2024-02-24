/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:15:36 by obahi             #+#    #+#             */
/*   Updated: 2023/07/27 09:55:07 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenizing(char **line)
{
	char	*token;
	int		i;

	printf ("\033[1;33m");
	i = ft_get_token(line, &token);
	while (i)
	{
		switch (i)
		{
			case T_PIPE :
				printf("pipe        : ");
				break;
			case T_AND :
				printf("and         : ");
				break;
			case T_OR :
				printf("or          : ");
				break;
			case T_LESS :
				printf("infile      : ");
				break;
			case T_LLESS :
				printf("heredoc     : ");
				break;
			case T_GREAT :
				printf("outfile     : ");
				break;
			case T_GGREAT :
				printf("append      : ");
				break;
			case T_WORD :
				printf("word        : ");
				break;
			case T_OPRNTHS :
			case T_CPRNTHS :
				printf("parentheses : ");
				break;
			default :
				printf("ERROR : ");
				break;
			
		}
		printf("~%s~\n", token);
		i = ft_get_token(line, &token);
	}
	printf ("\033[0;0m");
}
