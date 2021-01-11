# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 00:56:05 by student           #+#    #+#              #
#    Updated: 2020/05/27 00:56:07 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_print_c_s.c ft_print_id_u.c ft_print_p.c ft_print_x.c

OBJ = $(SRC:.c=.o)

INCLUDEDIR = ./

LIBFTDIR = ./libft/

LIBFT = $(LIBFTDIR)libft.a

HEADERS = $(INCLUDEDIR)ft_printf.h

FLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c $(HEADERS) $(LIBFT)
	gcc $(FLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) ./$(NAME)

clean:
	make clean -C $(LIBFTDIR)
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	/bin/rm -f $(NAME)

re: fclean all
