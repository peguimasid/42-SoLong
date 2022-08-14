# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:42:45 by gmasid            #+#    #+#              #
#    Updated: 2022/08/13 14:42:47 by gmasid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c	\
				ft_printf_utils.c	\
				ft_print_ptr.c \
				ft_print_hexa.c	\

OBJS	= $(SRCS:.c=.o)

.c.o:
		cc -Wall -Wextra -Werror -I include -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C ../libft && cp -v ../libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJS) $(BN_OBJS)
		make clean -C ../libft

fclean:	clean
		rm -f $(NAME)
		make fclean -C ../libft

re:	fclean all

.PHONY:	all clean fclean re