NAME=so_long
CC=cc

SRCS	= src/so_long.c	\

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	cd mlx && make -s
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	cd mlx && make -s clean
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
