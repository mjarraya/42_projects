# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 13:53:32 by mjarraya          #+#    #+#              #
#    Updated: 2016/01/06 14:53:07 by mjarraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c resolve.c utils.c check_file.c lists.c size.c tab.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	 	make -C libft/ 
		gcc -Wall -Wextra -Werror -Iincludes libft/libft.a $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)
		make -C libft/ fclean

fclean: clean
		rm -f $(NAME)

re: fclean all
