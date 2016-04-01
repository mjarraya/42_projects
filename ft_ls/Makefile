# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 14:07:54 by mjarraya          #+#    #+#              #
#    Updated: 2016/04/01 00:31:17 by mjarraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = error.c lists.c ls.c main.c parsing.c parsingopt.c parsingopt2.c print.c \
	print2.c print3.c printerror.c recu.c sort.c sort2.c sort3.c stat.c \
	stat2.c time.c time2.c utils.c utils2.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(LIB) -I/libft/includes $(SRC) -o $(NAME)

%.o:%.c
	gcc -c $(FLAGS) $< -o $@ -Ilibft/includes

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
