/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambiguous_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:46:46 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 14:52:21 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ambiguous_redirect(char *str)
{
	if (!str)
		return (1);
	else if (ft_word_count(str, ' ') > 1)
	{
		ft_free(&str);
		return (1);
	}
	else
		return (0);
}
