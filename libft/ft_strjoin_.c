/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:34:30 by obahi             #+#    #+#             */
/*   Updated: 2023/07/17 03:38:18 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_(char const *s1, char const *s2, char c)
{
	char	*join;
	char	*tmp;

	tmp = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (join)
	{
		tmp = join;
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp++ = c;
		*tmp = '\0';
	}
	return (join);
}
