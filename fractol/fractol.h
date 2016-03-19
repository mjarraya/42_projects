/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:54:35 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/19 19:41:13 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef	struct			s_info
{
	void				*mlx;
	void				*win;
}						t_info;

typedef	struct			s_fract
{
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom;
	double				image_x;
	double				image_y;
	double				imax;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;

}						t_fract;

#endif
