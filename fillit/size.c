/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:48:49 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:46:53 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	size_w(char **piece)
{
	int	i;
	int	j;
	int	width;

	j = 0;
	width = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (piece[i][j] != '.')
			{
				width++;
				break ;
			}
			i++;
		}
		j++;
	}
	return (width);
}

int	size_h(char **piece)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	height = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] != '.')
			{
				height++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (height);
}

int	size_x(char **piece)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 21;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == '#' && j < x)
				x = j;
			j++;
		}
		i++;
	}
	return (x);
}

int	size_y(char **piece)
{
	int	i;
	int	j;

	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
