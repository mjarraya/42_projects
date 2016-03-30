/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:14:00 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/30 16:51:17 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	double				x;
	double				y;
	double				z;
	int					val;
	int					pos;
	int					n_col;
}						t_fdf;

void					ft_draw_map(t_fdf *fdf, t_fdf *info);
t_fdf					*ft_3d_to_2d(t_fdf *fdf, int i, int deb, int size);
int						ft_key_funct(int keycode);
t_fdf					*ft_max_x(char *map, t_fdf *fdf);
void					init_fdf(t_fdf *fdf);
int						ft_get_next_nbr(char *str);
int						ft_count_numbers(char *str);
void					ft_fdf_error(int e);
char					*ft_fdf_read(char *file, int start);
void					ft_verif_fdf(char *map);
t_fdf					*ft_fdf_parse(char *map, int i, int x, int y);

t_fdf					*ft_min_z(t_fdf *fdf);

#endif
