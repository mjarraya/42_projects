/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:08:02 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/14 17:36:39 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_line_trace(t_fdf *info, t_fdf *i, t_fdf *f)
{
	int dx;
	int	dy;
	int	sx;
	int	sy;
	int	tab[2];

	dx = f->x < i->x ? i->x - f->x : f->x - i->x;
	dy = f->y < i->y ? i->y - f->y : f->y - i->y;
	sx = i->x < f->x ? 1 : -1;
	sy = i->y < f->y ? 1 : -1;
	tab[0] = (dx > dy ? dx : -dy) / 2;
	while (42)
	{
		mlx_pixel_put(info->mlx, info->win, i->x, i->y, 0xFFFFFF);
		if (i->x == f->x && i->y == f->y)
			break ;
		tab[1] = tab[0];
		if (tab[1] > -dx && (tab[0] -= dy))
			i->x += sx;
		if (tab[1] < dy && (tab[0] += dx))
			i->y += sy;
	}
	return (0);
}

int	ft_key_funct(int keycode, t_fdf *info)
{
	if (keycode == 53)
		exit(0);
	printf("keyevent %d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_fdf	*info;
	t_fdf	*a;
	t_fdf	*b;

	info = malloc(sizeof(t_fdf));
	a = malloc(sizeof(t_fdf));
	b = malloc(sizeof(t_fdf));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FIL DE FER\n");
	info->mlx = mlx;
	info->win = win;
	a->x = atoi(argv[1]);
	a->y = atoi(argv[2]);
	b->x = atoi(argv[3]);
	b->y = atoi(argv[4]);
	//ft_line_trace(info, a, b);
	mlx_pixel_put(mlx, win, a->x, a->y, 0xFF0000);
	mlx_pixel_put(mlx, win, b->x, b->y, 0xFF0000);
	mlx_key_hook(win, ft_key_funct, info);
	mlx_loop(mlx);
}
