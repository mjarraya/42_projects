/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:25:34 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/22 17:04:47 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

t_fdf	*ft_3d_to_2d(t_fdf *fdf, int i, int deb, int size)
{
	double	mult;

	if (fdf[0].n_col >= 50)
	{
		mult = fdf[0].n_col >= 100 ? fdf[0].n_col / 50 : fdf[0].n_col / 10;
		deb = 35;
		size = 40;
	}
	else if (fdf[0].n_col >= 25)
		mult = fdf[0].n_col / 2;
	else
		mult = fdf[0].n_col < 10 ? fdf[0].n_col * 10 : fdf[0].n_col * 14 / 10;
	deb = deb != 0 ? deb : 5;
	size = size != 0 ? size : 3 / 2;
	i = -1;
	while (i++ < fdf[0].pos)
	{
		fdf[i].x = (fdf[i].x + deb) * mult;
		fdf[i].y = (fdf[i].y + deb) * mult;
		fdf[i].y = (fdf[i].y + -fdf[i].z) + 300;
		fdf[i].z = fdf[i].z + i / (size);
		fdf[i].x = (fdf[i].x + -fdf[i].z) + 600;
	}
	return (fdf);
}

void	ft_pixel_put(t_fdf *info, t_fdf fdf, int col)
{
	if (col == 0)
		mlx_pixel_put(info->mlx, info->win, fdf.x, fdf.y, 0x006600);
	if (col == 1)
		mlx_pixel_put(info->mlx, info->win, fdf.x, fdf.y, 0xFFFFFF);
	if (col == 2)
		mlx_pixel_put(info->mlx, info->win, fdf.x, fdf.y, 0x996600);
}

void	ft_line_trace(t_fdf *info, t_fdf i, t_fdf f, int col)
{
	double	tab[4];
	double	err_tab[2];

	tab[2] = f.x < i.x ? i.x - f.x : f.x - i.x;
	tab[3] = f.y < i.y ? i.y - f.y : f.y - i.y;
	tab[0] = i.x < f.x ? 1 : -1;
	tab[1] = i.y < f.y ? 1 : -1;
	err_tab[0] = (double)(tab[2] > tab[3] ? tab[2] : -tab[3]) / 2;
	while (42)
	{
		ft_pixel_put(info, i, col);
		if (i.x == f.x && i.y == f.y)
			break ;
		err_tab[1] = err_tab[0];
		if (err_tab[1] > -tab[2])
		{
			err_tab[0] -= tab[3];
			i.x += tab[0];
		}
		if (err_tab[1] < tab[3])
		{
			err_tab[0] += tab[2];
			i.y += tab[1];
		}
	}
}

void	ft_draw_map(t_fdf *fdf, t_fdf *info)
{
	int	i;

	i = 0;
	while (i < fdf[0].pos)
	{
		if (i % fdf->n_col != 0)
		{
			if (fdf[i - 1].val > 27 && fdf[i].val > 27)
				ft_line_trace(info, fdf[i - 1], fdf[i], 1);
			else if (fdf[i - 1].val > 27 || fdf[i].val > 27)
				ft_line_trace(info, fdf[i - 1], fdf[i], 2);
			else
				ft_line_trace(info, fdf[i - 1], fdf[i], 0);
		}
		if (i + fdf->n_col < fdf[0].pos)
		{
			if (fdf[i].val > 27 && fdf[i + fdf->n_col].val > 27)
				ft_line_trace(info, fdf[i], fdf[i + fdf->n_col], 1);
			else if (fdf[i].val > 27 || fdf[i + fdf->n_col].val > 27)
				ft_line_trace(info, fdf[i], fdf[i + fdf->n_col], 2);
			else
				ft_line_trace(info, fdf[i], fdf[i + fdf->n_col], 0);
		}
		i++;
	}
}
