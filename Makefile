NAME = push_swap

INC_DIR = ./include
SRC_DIR = ./src

CC = cc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -Wsign-conversion

SRC_SOURCES = $(SRC_DIR)/main.c \
			  $(SRC_DIR)/ft_program.c \

SRC_OBJECTS = $(SRC_SOURCES:.c=.o)

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(SRC_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
