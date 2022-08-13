NAME=so_long
CC=cc

SRCS	= get_next_line/get_next_line.c	\
				get_next_line/get_next_line_utils.c	\
				src/so_long.c \
				src/handle_keypress.c	\
				src/generate_map.c
LIBFTPRINTF = ft_printf/libftprintf.a

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -s -C mlx
	make -s -C ft_printf
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFTPRINTF)

all: $(NAME)

clean:
	make clean -s -C mlx
	make clean -s -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C ft_printf
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
