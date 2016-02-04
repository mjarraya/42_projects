/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:18:04 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:47:28 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_split_tetri(char **tab, int start, int end)
{
	char	**piece;
	int		i;

	i = 0;
	piece = (char **)malloc(sizeof(char *) * 5);
	while (start <= end && tab[start])
	{
		piece[i] = ft_strdup(tab[start]);
		start++;
		i++;
	}
	piece[i] = 0;
	return (piece);
}

char	**pieces_intab(char *s)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		ret;
	int		i;
	char	**tab;

	i = 0;
	buf[545] = '\0';
	ft_bzero(buf, BUF_SIZE);
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	tab = ft_strsplit(buf, '\n');
	close(fd);
	return (tab);
}

t_tetri	*piece_inlist(int piece_nbr, char **tab)
{
	t_tetri	*begin;
	int		i;
	char	c;

	i = 0;
	c = 'A';
	begin = NULL;
	add_end(&begin, tetri_lstnew(ft_split_tetri(tab, i, i + 3), c));
	piece_nbr--;
	while (piece_nbr--)
	{
		i = i + 4;
		c = c + 1;
		add_end(&begin, tetri_lstnew(ft_split_tetri(tab, i, i + 3), c));
	}
	return (begin);
}

int		main(int argc, char **argv)
{
	int		piece_nbr;
	char	**split;
	t_tetri	*list;
	t_tab	tab;

	if (argc != 2 || ft_verif(argv[1]) == 0)
		ft_putstr("error\n");
	else
	{
		piece_nbr = ft_counttetri(ft_read(argv[1]));
		split = pieces_intab(argv[1]);
		list = piece_inlist(piece_nbr, split);
		ft_free_tab(split);
		tab = tab_init(2);
		while (solver(tab, list) == 1)
			tab = bigger_tab(tab);
		free_list(list);
		print_tab(tab);
		tab_free(&tab);
	}
	return (0);
}
