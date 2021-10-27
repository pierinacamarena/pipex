NAME = pipe

SRCS = pipex_bonus.c \
       		path_bonus.c \
		ft_strsplitbonus.c \
		basic_functionsbonus.c \
		utils_bonus.c

OBJS = $(SRCS:.c=.o)

CC = gcc

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
