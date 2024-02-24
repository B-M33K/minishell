/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:04:59 by obahi             #+#    #+#             */
/*   Updated: 2023/08/28 17:22:26 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <stdarg.h>

// types

# define CMD  1
# define PIPE  2
# define AND 3
# define OR 4
# define BLOCK 5

// tokens

# define T_OPRNTHS 1
# define T_CPRNTHS 2
# define T_AND 3
# define T_OR 4
# define T_PIPE 5
# define T_LESS 6
# define T_LLESS 7
# define T_GREAT 8
# define T_GGREAT 9
# define T_WORD 10
# define T_UNKNOWN -2

# define SPECIALS "#&\\[]{};!"

# define HERE_DOC "/tmp/.herdoc_"

//global struct

typedef struct s_glob
{
	int			ext;
	char		**environ;
	char		*path;
}	t_glob;
// tree node
typedef struct s_cmdline
{
	int	type;
}	t_cmdline;

// cmd here doc content

typedef struct s_content
{
	char				*line;
	struct s_content	*next;
}	t_content;

// io

typedef struct s_io
{
	int			type;
	char		*filename;
	t_content	*content;
	struct s_io	*next;
}	t_io;

// single commande
typedef struct s_cmd
{
	int			type;
	char		*path;
	t_content	*content;
	char		**args;
	void		(*builtins)(char **);
	t_io		*io;
}	t_cmd;

// pipe
typedef struct s_pipe
{
	int			type;
	t_cmdline	*left;
	t_cmdline	*right;
}	t_pipe;

// and
typedef struct s_and
{
	int			type;
	t_cmdline	*left;
	t_cmdline	*right;
}	t_and;

// or

typedef struct s_or
{
	int			type;
	t_cmdline	*left;
	t_cmdline	*right;
}	t_or;

// block
typedef struct s_block
{
	int			type;
	t_cmdline	*cmdline;
	t_io		*io;
}	t_block;

t_glob	g_;

char		*ft_absolute_path(char *cmd);
void		ft_add_content(t_content **content, t_content *new_content);
t_cmdline	*ft_and(t_cmdline *left, t_cmdline *right);
t_cmdline	*ft_block(void);
t_cmdline	*ft_cmd(void);
char		*ft_delimiter(char *str);
void		ft_exc_and(t_cmdline *cmdline);
void		ft_exc_block(t_cmdline *cmdline);
void		ft_exc_cmd(t_cmdline *cmdline);
void		ft_exc_cmdline(t_cmdline *cmdline);
void		ft_exc_or(t_cmdline *cmdline);
void		ft_exc_pipe(t_cmdline *cmdline);
char		*ft_expand_wildcard(void);
void		ft_free_and(t_cmdline *cmdline);
void		ft_free_block(t_cmdline *cmdline);
void		ft_free_cmd(t_cmdline *cmdline);
void		ft_free_cmdline(t_cmdline *cmdline);
void		ft_free_content(t_content *content);
void		ft_free_or(t_cmdline *cmdline);
void		ft_free_pipe(t_cmdline *cmdline);
int			ft_get_token(char **line, char **token);
int			ft_get_word(char *s, int *jj);
char		*ft_he_expand(char *str);
t_content	*ft_here_doc(char *limiter, int *he_status);
int			ft_here_doc_file(t_content	*content, int expand);
t_content	*ft_new_content(char *line);
t_cmdline	*ft_or(t_cmdline *left, t_cmdline *right);
void		ft_panic(char *key_word, char *error_msg, int ext);
t_cmdline	*ft_parce_and(char **line);
t_cmdline	*ft_parce_block(char **line);
t_cmdline	*ft_parce_cmd(char	**line);
t_cmdline	*ft_parce_cmdline(char **line);
t_cmdline	*ft_parce_or(char **line);
t_cmdline	*ft_parce_pipe(char **line);
int			ft_peak(char **line, char *toks);
int			ft_peak_2(char **line, char *toks);
t_cmdline	*ft_pipe(t_cmdline *left, t_cmdline *right);
// void		ft_print_cmdline(t_cmdline	*cmdline);
int			ft_redirect_input(t_io *in_file, int *fd_in);
int			ft_redirect_output(t_io *out_files, int *fd_out);
char		**ft_split_path(void);
char		*ft_strappend(char *str, char c);
int			ft_syntax_analysis(char *line);
void		ft_syntax_error(char *token);
int			ft_dup(int old_fd, int new_fd);
int			ft_execve(char *path, char **argv);
pid_t		ft_fork(void);
int			ft_open(char *pathname, int flags, mode_t mode);
void		ft_echo(char **args);
void		ft_cd(char **args);
void		ft_pwd(char **args);
void		ft_export(char **args);
void		ft_unset(char **args);
void		ft_env(char **args);
void		ft_exit(char **args);
void		ft_true(char **args);
void		ft_false(char **args);
int			ft_is_builtins(char *cmd, void (**builtins)(char **));
void		ft_sigint_handler(int sig);
void		ft_add_io(t_io **io, t_io *new_io);
t_io		*ft_io(int type, char *filename, int *he_status);
int			ft_redirect_io(t_io *io, int *fd_in, int *fd_out);
void		ft_free_io(t_io *io);
void		ft_default_env(char **env);
int			ft_is_identifier(char *str);
char		*ft_get_name(char *var);
char		*ft_get_value(char *var);
int			ft_name_does_exist(char *name);
int			ft_putenv(char *string);
int			ft_setenv(char *name, char *value, int ovrwrt);
char		*ft_getenv(char *name);
void		ft_declare(char **str);
void		ft_swap(char **a, char **b);
char		**ft_sort_env(void);
int			ft_unsetenv(char *name);
int			ft_chdir(char *path);
char		*ft_getcwd(void);
int			ft_content_size(t_content *content);
char		**ft_lst_2_char__(t_content *content);
t_content	*ft_expand_content(t_content *content);
void		ft_heredoc_sigint(int sig);
char		*ft_expand_quotes(char **line, char c);
char		*ft_expand_(char **line);
char		*ft_expand_exit_status(char **line);
char		*ft_expand_var(char **line, int i);
char		*ft_expand(char *str);
void		ft_perror(char *str, int ext);
int			ft_get_word_(char *str);
char		*ft_he_expand(char *str);
char		*ft_secure_strjoin(char *s1, char *s2);
char		*ft_expand_dollar(char **str, int i);
int			ft_ambiguous_redirect(char *str);

#endif