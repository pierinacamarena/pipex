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

SRCS = pipex.c \
		 utils.c \
		 path.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

all: $(NAME)

bonus: re
	@$(MAKE) fclean -C bonus
	@$(MAKE) -C pipex_bonus
	@cp ./pipex_bonus/pipex ./pipex

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	@$(MAKE) -C pipex_bonus clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C pipex_bonus fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
