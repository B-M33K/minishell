/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:12:51 by obahi             #+#    #+#             */
/*   Updated: 2023/08/26 07:10:35 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chdir(char *path)
{
	char	*key_word;
	int		ret;

	key_word = 0;
	ret = chdir(path);
	if (ret == -1)
	{
		key_word = ft_strjoin("cd : ", path);
		if (errno == ENOENT)
			ft_panic(key_word, "No such file or directory", 1);
		else if (errno == EACCES)
			ft_panic(key_word, "Permission denied", 1);
		else if (errno == ENOTDIR)
			ft_panic(key_word, "Not a directory", 1);
		else
			ft_perror("minishell : ", 1);
		ft_free(&key_word);
	}
	return (ret);
}
