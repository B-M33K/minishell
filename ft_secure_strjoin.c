/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:09:50 by obahi             #+#    #+#             */
/*   Updated: 2023/08/27 21:51:53 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_secure_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		str = ft_strdup(s2);
	else if (!s2)
		str = ft_strdup(s1);
	else
		str = ft_strjoin(s1, s2);
	return (str);
}
