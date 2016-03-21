/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:54:35 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/21 20:26:21 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef	struct			s_fract
{
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom_x;
	double				zoom_y;
	double				image_x;
	double				image_y;
	double				imax;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp_r;
	double				tmp_i;
	int					i;

}						t_fract;

typedef	struct			s_info
{
	int					pos[2];
	int					p;
	int					f;
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_data;
	int					nbit;
	int					deca_nbit;
	int					line;
	int					endian;
	struct s_fract		*fract;
}						t_info;

void	ft_mbrot(t_fract *m, t_info *info);
void	ft_julia(t_fract *j, t_info *info);
void	put_pixel_to_img(t_fract *m, int x, int y, t_info *info);
int		restart_fract(t_fract *fract, t_info *info);

#endif
