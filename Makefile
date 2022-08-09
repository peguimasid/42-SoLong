NAME=so_long
CC=cc

SRCS	= src/so_long.c
LIBFT = libft/libft.a

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -s -C mlx
	make -s -C libft
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

all: $(NAME)

clean:
	make clean -s -C mlx
	make clean -s -C libft
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
