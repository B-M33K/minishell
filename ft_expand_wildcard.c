/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:24:35 by obahi             #+#    #+#             */
/*   Updated: 2023/08/14 12:50:58 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_wildcard(void)
{
	DIR				*dir;
    struct dirent	*entry;
	char			*expand;
	char			*tmp;

	dir = opendir(".");
    if (dir == 0)
	{
        perror("minishell : ");
        g_exit = 1;
		return (0);
    }
	entry = 0;
	expand = ft_strdup("");
	entry = readdir(dir);
	while (entry)
	{
		if (*entry->d_name != '.')
		{
			tmp = expand;
			expand = ft_strjoin_(expand, entry->d_name, ' ');
			ft_free(&tmp);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (expand);
}
