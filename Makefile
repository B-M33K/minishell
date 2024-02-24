# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obahi <obahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 21:20:22 by obahi             #+#    #+#              #
#    Updated: 2023/08/14 12:35:42 by obahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

READLINE = $(shell brew --prefix readline)

INCLUDE_READLINE = $(addprefix $(READLINE),/include)

LIB_READLINE = $(addprefix $(READLINE),/lib)

MAKE = make

CFLAGS = -Wall -Wextra -Werror -g

HEADER = minishell.h

NAME = minishell

SRC := $(wildcard *.c)

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(LIBFT) -L $(LIB_READLINE) -lreadline $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDE_READLINE) -c $< -o $@

$(LIBFT) : $(LIBFT_HEADER)
	$(MAKE) -C libft

libft : $(LIBFT)

clean :
	$(RM) -f $(OBJ) $(MAN_OBJ) $(BON_OBJ)
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY : all clean fclean re libft bonus