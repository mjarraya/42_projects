/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:29:21 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:49:09 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_piece(t_tab tab, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (tab.tetri[i])
	{
		j = 0;
		while (tab.tetri[i][j])
		{
			if (tab.tetri[i][j] == letter)
				tab.tetri[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		valid_piece(int l, int c, t_tab tab, t_tetri *list)
{
	int	i;
	int	j;

	if (l + list->height > tab.height)
		return (1);
	if (c + list->width > tab.width)
		return (1);
	i = list->y;
	while (i < list->y + list->height)
	{
		j = list->x;
		while (j < list->x + list->width)
		{
			if (list->tetri[i][j] == '#' &&
					tab.tetri[l + i - list->y][c + j - list->x] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		put_piece(t_tab tab, t_tetri *list, int l, int c)
{
	int	i;
	int	j;

	i = list->y;
	while (i < list->y + list->height)
	{
		j = list->x;
		while (j <= list->x + list->width)
		{
			if (list->tetri[i][j] == '#')
				tab.tetri[l + i - list->y][c + j - list->x] = list->letter;
			j++;
		}
		i++;
	}
	return (0);
}

int		solver(t_tab tab, t_tetri *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab.height)
	{
		j = 0;
		while (j < tab.width)
		{
			if (valid_piece(i, j, tab, list) == 0)
			{
				put_piece(tab, list, i, j);
				if (!list->next)
					return (0);
				if (solver(tab, list->next) == 0)
					return (0);
				else
					remove_piece(tab, list->letter);
			}
			j++;
		}
		i++;
	}
	return (1);
}
