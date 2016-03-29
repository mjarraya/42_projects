/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:40:52 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 16:46:30 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract	*ft_bship_init(void)
{
	t_fract	*b;

	b = ft_memalloc(sizeof(t_fract));
	b->x1 = -1.5;
	b->x2 = 1.5;
	b->y1 = -1;
	b->y2 = 1;
	b->image_x = 800;
	b->image_y = 800;
	b->zoom_x = b->image_x / (b->x2 - b->x1);
	b->zoom_y = b->image_y / (b->y2 - b->y1);
	b->imax = 42;
	b->c_r = 0;
	b->c_i = 0;
	b->z_r = 0;
	b->z_i = 0;
	b->tmp_r = 0;
	b->tmp_i = 0;
	b->i = 10;
	return (b);
}

void	ft_bship(t_fract *b, t_info *info)
{
	double	x;
	double	y;
	double	tmp;

	info->f = 3;
	x = -1;
	while (++x < b->image_x)
	{
		y = -1;
		while (++y < b->image_y)
		{
			b->c_r = x / b->zoom_x + b->x1;
			b->c_i = y / b->zoom_y + b->y1;
			b->z_r = b->tmp_r;
			b->z_i = b->tmp_i;
			b->i = -1;
			while (b->z_r * b->z_r + b->z_i * b->z_i < 4 && ++b->i < b->imax)
			{
				tmp = b->z_r;
				b->z_r = b->z_r * b->z_r - b->z_i * b->z_i - b->c_r;
				b->z_i = 2 * ft_abs(b->z_i) * ft_abs(tmp) + b->c_i;
			}
			put_pixel_to_img(b, x, y, info);
		}
	}
}
