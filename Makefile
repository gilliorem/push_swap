NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRC = main.c parse.c stack_basic.c stack_utils.c \
      op_swap.c op_push.c op_rotate.c op_reverse.c \
      sort_small.c index.c sort_big.c utils.c
OBJ = $(addprefix $(SRC_DIR)/,$(SRC:.c=.o))
INCLUDES = -Iinclude -Ift_printf
FT_DIR = ft_printf
FT_LIB = $(FT_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(FT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(FT_LIB) -o $(NAME)

$(FT_LIB):
	$(MAKE) -C $(FT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
