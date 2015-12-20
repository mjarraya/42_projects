# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 14:42:56 by mjarraya          #+#    #+#              #
#    Updated: 2015/12/09 10:49:51 by mjarraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_putstr.c ft_strsplit.c ft_readfillit.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror -Iincludes $(SRC)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
