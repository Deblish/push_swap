NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SOURCES = main.c \
			  stack_utils.c \
			  stack_operation_push.c \
			  stack_operation_swap.c \
			  stack_operation_reverse.c \
			  stack_operation_rotate.c \
			  algo_utils.c \
			  algo_utils_a.c \
			  algo_utils_b.c \
			  algo.c \

SRC_OBJECTS = $(SRC_SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC_OBJECTS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a ./ft_printf/libftprintf.a

clean:
	rm -f $(SRC_OBJECTS)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
