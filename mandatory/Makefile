NAME = push_swap

SRC = also_sort.c\
	check.c\
	ft_atoi.c\
	push_swap.c\
	reverse_and_rotate.c\
	sort.c\
	swap_and_push.c\

HDRS = push_swap.h

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		$(CC) $(FLAGS) -I mlx $(OBJ) -I. -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean
