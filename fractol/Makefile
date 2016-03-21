# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 14:07:54 by mjarraya          #+#    #+#              #
#    Updated: 2016/03/21 14:50:09 by mjarraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3

FW = -lmlx -framework OpenGL -framework AppKit

LIB = -L/usr/local/lib libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(LIB) -I/usr/local/include $(FW) $(SRC) -o $(NAME)

%.o:%.c
	gcc -c $(FLAGS) $< -o $@ -Iincludes

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
