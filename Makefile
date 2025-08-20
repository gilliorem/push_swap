NAME =		push_swap
CC =		gcc
CFLAGS = 	-Wall -Wextra -Werror -g
RM = 		rm -rf
SRC = 		parsing.c \
		main.c
OBJ = $(SRC:.c=.o)
INC_DIRS = . ft_printf libft
INCLUDES = $(addprefix -I,$(INC_DIRS))
LIBDIR = ft_printf
LIBA = $(LIBDIR)/libftprintf.a
LIBS =


$(NAME): $(OBJ) $(LIBA)
		$(NAME) $(OBJ)

all : $(NAME)

clean : 
		$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
