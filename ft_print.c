/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:26:22 by obahi             #+#    #+#             */
/*   Updated: 2024/02/23 02:41:06 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_print_cmdline(t_cmdline	*cmdline)
// {
// 	t_cmd	*cmd;
// 	t_input		*inputs;
// 	t_output	*outputs;

// 	cmd = (t_cmd *) cmdline;
// 	inputs = cmd->in_files;
// 	outputs = cmd->out_files;
// 	printf("type = %d\n",cmd->type);
// 	printf("path = %s\n",cmd->path);
// 	printf("---args---\n");
// 	printf("cmd = %s\n",cmd->cmd);
// 	printf("----infiles----\n");
// 	while (inputs)
// 	{
// 		printf("- !%s!\n",inputs->filename);
// 		inputs = inputs->next;
// 	}
// 	printf("----outfiles----\n");
// 	while (outputs)
// 	{
// 		printf("- !%s!\n",outputs->filename);
// 		outputs = outputs->next;
// 	}
// }

void	ft_print_line(t_cmdline *cmdline, int level)
{
	t_pipe	*pip;
	t_and	*and;
	t_or	*or;
	t_block	*block;
	t_cmd	*cmd;
	int		i;

	printf ("\033[1;35m");
	i = 0;
	while (i < level)
	{
		printf("├   ");
		i++;
	}
	i = cmdline->type;
	switch (i)
	{
		case CMD :
			cmd = (t_cmd *)cmdline;
			printf("├── cmd %s\n", cmd->cmd);
			break;
		case PIPE :
			printf("├── pipe \n");
			pip = (t_pipe *)cmdline; 
			ft_print_line(pip->left, level + 1);
			ft_print_line(pip->right, level + 1);
			break;
		case AND :
			printf("├── and \n");
			and = (t_and *)cmdline; 
			ft_print_line(and->left, level + 1);
			ft_print_line(and->right, level + 1);
			break;
		case OR :
			printf("├── or \n");
			or = (t_or *)cmdline; 
			ft_print_line(or->left, level + 1);
			ft_print_line(or->right, level + 1);
			break;
		case BLOCK :
			printf("├── block \n");
			block = (t_block *)cmdline;
			ft_print_line(block->cmdline, level + 1);
		default :
			break;
	}
	printf ("\033[0m");
}
