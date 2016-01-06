/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:55:04 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:53:50 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

# define BUF_SIZE 546

typedef struct		s_tab
{
	char			**tetri;
	int				height;
	int				width;
	int				pos_x;
	int				pos_y;
}					t_tab;

typedef struct		s_tetri
{
	char			**tetri;
	int				height;
	int				width;
	int				x;
	int				y;
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

int					size_y(char **piece);
int					size_x(char **piece);
int					size_w(char **piece);
int					size_h(char **piece);
int					ft_verif(char *read);
char				*ft_read(char *s);
int					ft_validmap(char *s);
void				ft_free_tab(char **tab);
t_tetri				*tetri_lstnew(char **piece, char letter);
void				add_end(t_tetri **begin, t_tetri *new);
void				free_list(t_tetri *list);
void				print_tab(t_tab tab);
void				tab_free(t_tab *tab);
t_tab				bigger_tab(t_tab tab);
t_tab				tab_init(int size);
char				*ft_newline(int	size);
int					ft_counttetri(char *s);
int					solver(t_tab tab, t_tetri *list);
int					put_piece(t_tab tab, t_tetri *list, int l, int c);
int					valid_piece(int	l, int c, t_tab tab, t_tetri *list);
void				remove_piece(t_tab tab, char letter);

#endif
