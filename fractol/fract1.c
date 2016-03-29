/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:34:01 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 17:31:45 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract	*ft_julia_init(void)
{
	t_fract	*j;

	j = ft_memalloc(sizeof(t_fract));
	j->x1 = -1.5;
	j->x2 = 1.5;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->image_x = 800;
	j->image_y = 800;
	j->zoom_x = j->image_x / (j->x2 - j->x1);
	j->zoom_y = j->image_y / (j->y2 - j->y1);
	j->imax = 50;
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

	info->f = 2;
	x = -1;
	while (++x < j->image_x)
	{
		y = -1;
		while (++y < j->image_y)
		{
			j->z_r = x / j->zoom_x + j->x1;
			j->z_i = y / j->zoom_y + j->y1;
			j->c_r = j->tmp_r;
			j->c_i = j->tmp_i;
			j->i = -1;
			while (j->z_r * j->z_r + j->z_i * j->z_i < 4 && ++j->i < j->imax)
			{
				tmp = j->z_r;
				j->z_r = j->z_r * j->z_r - j->z_i * j->z_i + j->c_r;
				j->z_i = 2 * j->z_i * tmp + j->c_i;
			}
			put_pixel_to_img(j, x, y, info);
		}
	}
}
