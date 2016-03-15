/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:14:00 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/15 20:03:23 by mjarraya         ###   ########.fr       */
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
	int					x;
	int					y;
	int					z;
	int					pos;
	int					nbr_line;
	int					nbr_col;
}						t_fdf;

#endif
