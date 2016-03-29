/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:41:01 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 16:43:21 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(void *param)
{
	t_info	*info;

	info = param;
	exit(1);
}

int		ft_key_funct(int keycode, void *param)
{
	t_info	*info;
	t_fract	*fract;
	int		z_x;
	int		z_y;

	info = param;
	fract = info->fract;
	z_x = info->fract->zoom_x;
	z_y = info->fract->zoom_y;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		info->p = info->p ? 0 : 1;
	restart_fract(fract, info);
	return (0);
}

void	ft_zoom(int button, t_info *info)
{
	if (button == 4)
	{
		info->fract->zoom_x = info->fract->zoom_x * 2;
		info->fract->zoom_y = info->fract->zoom_y * 2;
		info->fract->imax += 10;
	}
	if (button == 5)
	{
		info->fract->zoom_x = info->fract->zoom_x / 2;
		info->fract->zoom_y = info->fract->zoom_y / 2;
		info->fract->imax -= 10;
	}
}

int		ft_mouse_scroll(int button, int x, int y, void *param)
{
	t_fract	*fract;
	t_info	*info;
	double	z_x;
	double	z_y;

	info = param;
	fract = info->fract;
	if (info->p != 1)
		return (1);
	z_x = info->fract->zoom_x;
	z_y = info->fract->zoom_y;
	ft_zoom(button, info);
	info->fract->x1 += x / z_x - (x / info->fract->zoom_x);
	info->fract->y1 += y / z_y - (y / info->fract->zoom_y);
	restart_fract(fract, info);
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
		restart_fract(fract, info);
	}
	return (0);
}
