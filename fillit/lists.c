/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:13:48 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:46:17 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*tetri_lstnew(char **piece, char letter)
{
	t_tetri	*new;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	new->tetri = piece;
	new->letter = letter;
	new->width = size_w(piece);
	new->height = size_h(piece);
	new->x = size_x(piece);
	new->y = size_y(piece);
	return (new);
}

void		add_end(t_tetri **begin, t_tetri *new)
{
	t_tetri	*cur;

	if (!*begin)
	{
		*begin = new;
		return ;
	}
	cur = *begin;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void		free_list(t_tetri *list)
{
	int		i;
	t_tetri	*tmp;

	i = 0;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		ft_free_tab(tmp->tetri);
		tmp->tetri = NULL;
		free(tmp);
	}
	free(list);
}
