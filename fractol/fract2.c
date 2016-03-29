/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:34:05 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 16:46:11 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract	*ft_mbrot_init(void)
{
	t_fract	*m;

	m = ft_memalloc(sizeof(t_fract));
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->image_x = 800;
	m->image_y = 800;
	m->zoom_x = m->image_x / (m->x2 - m->x1);
	m->zoom_y = m->image_y / (m->y2 - m->y1);
	m->imax = 50;
	m->c_r = 0;
	m->c_i = 0;
	m->z_r = 0;
	m->z_i = 0;
	m->tmp_r = 0;
	m->tmp_i = 0;
	m->i = 0;
	return (m);
}

void	ft_mbrot(t_fract *m, t_info *info)
{
	double	x;
	double	y;
	double	tmp;

	info->f = 1;
	x = -1;
	while (++x < m->image_x)
	{
		y = -1;
		while (++y < m->image_y)
		{
			m->c_r = x / m->zoom_x + m->x1;
			m->c_i = y / m->zoom_y + m->y1;
			m->z_r = m->tmp_r;
			m->z_i = m->tmp_i;
			m->i = -1;
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && ++m->i < m->imax)
			{
				tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * tmp + m->c_i;
			}
			put_pixel_to_img(m, x, y, info);
		}
	}
}
