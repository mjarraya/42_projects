/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:55:03 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/21 17:26:08 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_key_funct(int keycode, void *param)
{
	t_info	*info;

	info = param;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		info->p = info->p ? 0 : 1;
	return (0);
}

int		restart_fract(t_fract *fract, t_info *info)
{
	mlx_destroy_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, 1000, 1000);
	info->img_data = mlx_get_data_addr(info->img, &info->nbit, &info->line,
	&info->endian);
	if (info->f == 1)
		ft_mbrot(fract, info);
	if (info->f == 2)
		ft_julia(fract, info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	return (0);
}

int		ft_mouse_scroll(int button, int x, int y, void *param)//, int x, int y)//, void *param)
{
	t_fract	*fract;
	t_info	*info;

	info = param;
	fract = info->fract;
	if (info->p == 1 && button == 4) // down
	{
		info->fract-> = info->fract->zoom - 1;
		printf("zoom: %f\n", info->fract->zoom);
	}
	if (info->p == 1 && button == 5) // up
	{
		printf("button: %d, x: %d, y: %d\n", button, x, y);
	}
	return (0);
}

int		ft_mouse_funct(int x, int y, void *param)
{
	t_fract	*fract;
	t_info	*info;

	info = param;
	fract = info->fract;
	if (info->p == 0)
	{
		info->fract->tmp_r = (double)(x - 500) / 500;
		info->fract->tmp_i = (double)(y - 500) / 500;
	}
	restart_fract(fract, info);
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

t_fract	*ft_julia_init(void)
{
	t_fract	*j;

	j = ft_memalloc(sizeof(t_fract));
	j->x1 = -1;
	j->x2 = 1;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->zoom = 350;
	//j->image_x = (j->x2 - j->x1) * j->zoom;
	//j->image_y = (j->y2 - j->y1) * j->zoom;
	j->image_x = 1000;
	j->image_y = 1000;
	j->imax = 20;
	j->c_r = 0;
	j->c_i = 0;
	j->z_r = 0;
	j->z_i = 0;
	j->tmp_r = 0.285;
	j->tmp_i = 0.01;
	j->i = 0;
	return (j);
}

void	ft_julia(t_fract *j, t_info *info)
{
	double	x;
	double	y;
	double	tmp;

	x = 0;
	info->f = 2;
	while (x < j->image_x)
	{
		y = 0;
		while (y < j->image_y)
		{
			j->z_r = x / j->zoom + j->x1;
			j->z_i = y / j->zoom + j->y1;
			j->c_r = j->tmp_r;
			j->c_i = j->tmp_i;
			j->i = 0;
			while (j->z_r * j->z_r + j->z_i * j->z_i < 4 && j->i < j->imax)
			{
				tmp = j->z_r;
				j->z_r = j->z_r * j->z_r - j->z_i * j->z_i + j->c_r;
				j->z_i = 2 * j->z_i * tmp + j->c_i;
				j->i++;
			}
			put_pixel_to_img(j, x, y, info);
			y++;
		}
		x++;
	}
}

t_fract	*ft_mbrot_init(void)
{
	t_fract	*m;

	m = ft_memalloc(sizeof(t_fract));
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom = 350;
	m->image_x = (m->x2 - m->x1) * m->zoom;
	m->image_y = (m->y2 - m->y1) * m->zoom;
	m->imax = 30;
	m->c_r = 0;
	m->c_i = 0;
	m->z_r = 0;
	m->z_i = 0;
	m->tmp_r = 0;
	m->tmp_i = 0;
	m->i = 0;
	return (m);
}

void	put_pixel_to_img(t_fract *m, int x, int y, t_info *info)
{
	if (m->i == m->imax)
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 255;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 102;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = 102;
	}
	else
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 100;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 100;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] =
													m->i * 255 / m->imax;
	}
}

void	ft_mbrot(t_fract *m, t_info *info)
{
	double	x;
	double	y;
	double	tmp;

	info->f = 1;
	x = 0;
	while (x < m->image_x)
	{
		y = 0;
		while (y < m->image_y)
		{
			m->c_r = x / m->zoom + m->x1;
			m->c_i = y / m->zoom + m->y1;
			m->z_r = m->tmp_r;
			m->z_i = m->tmp_i;
			m->i = 0;
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && m->i < m->imax)
			{
				tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * tmp + m->c_i;
				m->i++;
			}
			put_pixel_to_img(m, x, y, info);
			y++;
		}
		x++;
	}
}

void	ft_fractol(char *file)
{
	t_info	*info;
	t_fract	*fract;

	if (!(ft_fractol_verif(file)))
		ft_fractol_err(0);
	info = ft_memalloc(sizeof(t_info));
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 940, 840, "Fract'ol\n");
	if (ft_fractol_verif(file) == 1)
	{
		fract = ft_mbrot_init();
		info->fract = fract;
		info->img = mlx_new_image(info->mlx, 1000, 1000);
		info->img_data = mlx_get_data_addr(info->img, &info->nbit, &info->line,
		&info->endian);
		info->deca_nbit = info->nbit >> 3;
		ft_mbrot(fract, info);
		mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	}
	else if (ft_fractol_verif(file) == 2)
	{
		fract = ft_julia_init();
		info->fract = fract;
		info->img = mlx_new_image(info->mlx, 1000, 1000);
		info->img_data = mlx_get_data_addr(info->img, &info->nbit, &info->line,
		&info->endian);
		info->deca_nbit = info->nbit >> 3;
		ft_julia(fract, info);
		mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	}
	else if (ft_fractol_verif(file) == 3)
		ft_fract3();
	mlx_hook(info->win, 2, 0, ft_key_funct, info);
	mlx_hook(info->win, 4, 0, ft_mouse_scroll, info);
	mlx_hook(info->win, 6, 0, ft_mouse_funct, info);
	mlx_loop(info->mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_fractol_err(0);
	ft_fractol(argv[1]);
	return (0);
}
