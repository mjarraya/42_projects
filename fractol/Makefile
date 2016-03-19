# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 14:07:54 by mjarraya          #+#    #+#              #
#    Updated: 2016/03/19 14:11:21 by mjarraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FW = -lmlx -framework OpenGL -framework AppKit

LIB = -L/usr/local/lib libft/libft.a

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
