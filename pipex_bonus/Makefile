# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 19:48:33 by pcamaren          #+#    #+#              #
#    Updated: 2021/10/06 17:15:41 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = src/pipex_bonus.c \
       		src/path_bonus.c \
		src/ft_strsplitbonus.c \
		src/basic_functionsbonus.c \
		src/multipipe.c \
		src/cmd_splitbonus.c \
		src/cmdsplit_utilsbonus.c \
		src/split_utilsbonus.c \
		src/utils_bonus.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror 

INCLUDES = -I./includes

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

.PHONY: fclean all
