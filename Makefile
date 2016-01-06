# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:39:22 by aribeiro          #+#    #+#              #
#    Updated: 2016/01/06 00:36:20 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	main.c \
		ft_verif.c \
		ft_tetritab.c \
		ft_putstr_error.c \
		ft_tools.c \
		ft_malloc_template_free.c \
		ft_resolution.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_memset.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o:%.c
	gcc -c $< $(FLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
