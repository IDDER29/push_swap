NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c push_ops.c swap_ops.c rotate_ops.c reverse_rotate_ops.c three_ops.c indexing.c cost.c stack_init.c utils.c ft_printf.c ft_printf_utils.c ft_print_str.c ft_strlen.c
OBJS = $(SRCS:.c=.o)

HEADS = push_swap.h ft_printf.h

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I. -o $@ $^

%.o: %.c $(HEADS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all