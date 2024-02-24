# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obahi <obahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 21:20:22 by obahi             #+#    #+#              #
#    Updated: 2023/08/28 14:49:46 by obahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

READLINE = $(shell brew --prefix readline)

INCLUDE_READLINE = $(addprefix $(READLINE),/include)

LIB_READLINE = $(addprefix $(READLINE),/lib)

MAKE = make

CFLAGS =  -Wall -Wextra -Werror 

HEADER = minishell.h

LIBFT_HEADER = libft/libft.h

NAME = minishell

LIBFT_SRC :=	libft/ft_atoi.c \
				libft/ft_atoll.c \
				libft/ft_atosize_t.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_free.c \
				libft/ft_free2.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_isspace.c \
				libft/ft_itoa.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_putstrstr_fd.c \
				libft/ft_split.c \
				libft/ft_str_join.c \
				libft/ft_strchr.c \
				libft/ft_strcmp.c \
				libft/ft_strdup.c \
				libft/ft_striteri.c \
				libft/ft_strjoin.c \
				libft/ft_strjoin_.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strmapi.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_strrchr.c \
				libft/ft_strstr.c \
				libft/ft_strstrdup.c \
				libft/ft_strstrlen.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_word_count.c \
				libft/get_next_line.c

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

SRC := 	ft_absolute_path.c \
		ft_add_content.c \
		ft_add_io.c \
		ft_and.c \
		ft_block.c \
		ft_cd.c \
		ft_chdir.c \
		ft_cmd.c \
		ft_content_size.c \
		ft_declare.c \
		ft_default_env.c \
		ft_delimiter.c \
		ft_dup.c \
		ft_echo.c \
		ft_env.c \
		ft_exc_and.c \
		ft_exc_block.c \
		ft_exc_cmd.c \
		ft_exc_cmdline.c \
		ft_exc_or.c \
		ft_exc_pipe.c \
		ft_execve.c \
		ft_exit.c \
		ft_expand.c \
		ft_expand_content.c \
		ft_expand_exit_status.c \
		ft_expand_quotes.c \
		ft_expand_var.c \
		ft_expand_wildcard.c \
		ft_export.c \
		ft_false.c \
		ft_fork.c \
		ft_free_and.c \
		ft_free_block.c \
		ft_free_cmd.c \
		ft_free_cmdline.c \
		ft_free_content.c \
		ft_expand_dollar.c \
		ft_free_io.c \
		ft_free_or.c \
		ft_free_pipe.c \
		ft_get_name.c \
		ft_get_token.c \
		ft_get_value.c \
		ft_get_word.c \
		ft_get_word_.c \
		ft_getcwd.c \
		ft_getenv.c \
		ft_he_expand.c \
		ft_here_doc.c \
		ft_here_doc_file.c \
		ft_io.c \
		ft_is_builtins.c \
		ft_is_identifier.c \
		ft_lst_2_char__.c \
		ft_name_does_exist.c \
		ft_new_content.c \
		ft_open.c \
		ft_or.c \
		ft_panic.c \
		ft_parce_and.c \
		ft_parce_block.c \
		ft_parce_cmd.c \
		ft_parce_cmdline.c \
		ft_parce_or.c \
		ft_parce_pipe.c \
		ft_peak.c \
		ft_peak_2.c \
		ft_perror.c \
		ft_pipe.c \
		ft_putenv.c \
		ft_pwd.c \
		ft_redirect_input.c \
		ft_redirect_io.c \
		ft_redirect_output.c \
		ft_secure_strjoin.c \
		ft_setenv.c \
		ft_signal_handler.c \
		ft_sort_env.c \
		ft_split_path.c \
		ft_strappend.c \
		ft_syntax_analysis.c \
		ft_syntax_error.c \
		ft_true.c \
		ft_unset.c \
		ft_unsetenv.c \
		ft_ambiguous_redirect.c \
		minishell.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all : $(NAME) 

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -L $(LIB_READLINE) -lreadline $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDE_READLINE) -c $< -o $@

$(LIBFT) : $(LIBFT_OBJ) $(LIBFT_HEADER)
	$(MAKE) -C libft

libft : $(LIBFT)

clean :
	$(RM) -f $(OBJ)
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY : all clean fclean re libft