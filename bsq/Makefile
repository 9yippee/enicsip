CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= bsq
SRCS= main.c sub.c
OBJS= main.o sub.o


all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $^ 

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, re
