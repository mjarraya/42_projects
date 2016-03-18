# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/18 19:32:43 by mjarraya          #+#    #+#              #
#    Updated: 2016/03/18 19:45:10 by mjarraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = draw.c parse.c utils.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FW = -lmlx -framework OpenGL -framework AppKit

LIB =  -L/usr/local/lib/ libft/libft.a


all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) $(LIB) -I/usr/local/include $(FW) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
