/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:33:38 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 16:37:48 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img_burn(t_fract *m, int x, int y, t_info *info)
{
	if (m->i == m->imax)
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 60;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 65;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = 50;
	}
	else
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 52;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 50;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] =
													m->i * 255 / m->imax;
	}
}

void	put_pixel_to_img_orange(t_fract *m, int x, int y, t_info *info)
{
	if (m->i == m->imax)
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 0;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 102;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = 230;
	}
	else
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 0;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 200;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] =
													m->i * 255 / m->imax;
	}
}

void	put_pixel_to_img_blue(t_fract *m, int x, int y, t_info *info)
{
	if (m->i == m->imax)
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 168;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 185;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = 2;
	}
	else
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 255;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 127;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] =
													m->i * 255 / m->imax;
	}
}

void	put_pixel_to_img_bw(t_fract *m, int x, int y, t_info *info)
{
	if (m->i == m->imax)
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 255;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 255;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = 255;
	}
	else
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = 0;
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = 0;
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = 0;
	}
}

void	put_pixel_to_img_rand(t_fract *m, int x, int y, t_info *info)
{
	if (m->i == m->imax)
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = info->r[0];
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = info->r[1];
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] = info->r[2];
	}
	else
	{
		info->img_data[x * info->deca_nbit + (y * info->line)] = info->r[3];
		info->img_data[x * info->deca_nbit + (y * info->line) + 1] = info->r[4];
		info->img_data[x * info->deca_nbit + (y * info->line) + 2] =
													m->i * 255 / m->imax;
	}
}
