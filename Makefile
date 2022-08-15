NAME=so_long
CC=cc

SRCS	= lib/get_next_line/get_next_line.c	\
				lib/get_next_line/get_next_line_utils.c	\
				src/so_long.c \
				src/common.c \
				src/handle_keypress.c	\
				src/generate_map.c	\
				src/print_map.c	\
				src/set_game_config.c	\
				src/validate_map.c	\
				src/validate_map_utils.c

LIBFTPRINTF = lib/ft_printf/libftprintf.a

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -s -C mlx
	make -s -C lib/ft_printf
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFTPRINTF)

all: $(NAME)

clean:
	make clean -s -C mlx
	make clean -s -C lib/ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/ft_printf
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
