NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address #-Wsign-conversion

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
#			  ../ft_printf/src/ft_printf.c \
			  ../ft_printf/src/ft_putchar.c \
			  ../ft_printf/src/ft_putnbr.c \
			  ../ft_printf/src/ft_putnbr_u.c \
			  ../ft_printf/src/ft_putstr.c \
			  ../ft_printf/src/ft_strlen.c \
#			  ../libft/ft_atoi.c \
			  ../libft/ft_isdigit.c \
			  ../libft/ft_split.c \
			  ../libft/ft_strchr.c \
			  ../libft/ft_substr.c \
			  ../libft/ft_strdup.c \
			  ../libft/ft_strlcpy.c \
			  ../libft/ft_strncmp.c \
			  ../libft/int_overflows.c \
			  ../libft/has_duplicates.c \

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
