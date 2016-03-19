/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:55:03 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/19 19:41:08 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_mouse_funct(int x, int y)//, void *param)
{
	//t_fract	*a;

	//a = param;
	if (x > 0 && x < 800 && y > 0 && y < 600)
		printf("x:%d, y:%d\n", x, y);
	return (0);
}

void	ft_fractol_err(int e)
{
	if (e == 0)
		ft_putendl_fd("Usage: ./fdf fractal_name (mandelbrot/julia/fract3)", 2);
	exit(1);
}

int		ft_fractol_verif(char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(name, "julia") == 0)
		return (2);
	if (ft_strcmp(name, "fract3") == 0)
		return (3);
	else
		return (0);
}

void	ft_fract3()
{
}

void	ft_julia_init(t_fract *j)
{
	j->x1 = -1;
	j->x2 = 1;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->zoom = 200;
	j->image_x = (j->x2 - j->x1) * j->zoom;
	j->image_y = (j->y2 - j->y1) * j->zoom;
	j->imax = 150;
	j->c_r = 0;
	j->c_i = 0;
	j->z_r = 0;
	j->z_i = 0;
}

void	ft_julia(t_info *info)
{
	double	x;
	double	y;
	double	i;
	double	tmp;
	t_fract	*j;

	j = ft_memalloc(sizeof(t_fract));
	ft_julia_init(j);
	x = 0;
	while (x < j->image_x)
	{
		y = 0;
		while (y < j->image_y)
		{
			j->c_r = 0.285;
			j->c_i = 0.01;
			j->z_r = x / j->zoom + j->x1;
			j->z_i = y / j->zoom + j->y1;
			i = 0;
			while (j->z_r * j->z_r + j->z_i * j->z_i < 4 && i < j->imax)
			{
				tmp = j->z_r;
				j->z_r = j->z_r * j->z_r - j->z_i * j->z_i + j->c_r;
				j->z_i = 2 * j->z_i * tmp + j->c_i;
				i++;
			}
			if (i == j->imax)
				mlx_pixel_put(info->mlx, info->win, x, y, 0x000000);
			else
				mlx_pixel_put(info->mlx, info->win, x, y, i * 255 / j->imax);
			y++;
		}
		x++;
	}
}

void	ft_mbrot_init(t_fract *m)
{
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom = 200;
	m->image_x = (m->x2 - m->x1) * m->zoom;
	m->image_y = (m->y2 - m->y1) * m->zoom;
	m->imax = 50;
	m->c_r = 0;
	m->c_i = 0;
	m->z_r = 0;
	m->z_i = 0;
}

void	ft_mbrot(t_info *info)
{
	double	x;
	double	y;
	double	i;
	double	tmp;
	t_fract	*m;

	m = ft_memalloc(sizeof(t_fract));
	ft_mbrot_init(m);
	x = 0;
	while (x < m->image_x)
	{
		y = 0;
		while (y < m->image_y)
		{
			m->c_r = x / m->zoom + m->x1;
			m->c_i = y / m->zoom + m->y1;
			m->z_r = 0;
			m->z_i = 0;
			i = 0;
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && i < m->imax)
			{
				tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * tmp + m->c_i;
				i++;
			}
			if (i == m->imax)
				mlx_pixel_put(info->mlx, info->win, x, y, 0x000000);
			else
				mlx_pixel_put(info->mlx, info->win, x, y, i * 255 / m->imax);
			y++;
		}
		x++;
	}
}

void	ft_fractol(char *file)
{
	t_info	*info;

	if (!(ft_fractol_verif(file)))
		ft_fractol_err(0);
	info = ft_memalloc(sizeof(t_info));
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 800, 600, "Fract'ol\n");
	if (ft_fractol_verif(file) == 1)
		ft_mbrot(info);
	else if (ft_fractol_verif(file) == 2)
		ft_julia(info);
	else if (ft_fractol_verif(file) == 3)
		ft_fract3();
	mlx_hook(info->win, 6, 0, ft_mouse_funct, info);
	mlx_hook(info->win, 2, 0, ft_key_funct, info);
	mlx_loop(info->mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_fractol_err(0);
	ft_fractol(argv[1]);
	return (0);
}
