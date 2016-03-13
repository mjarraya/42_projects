/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:14:00 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/13 14:13:19 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include "fcntl.h"

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	int					x;
	int					y;
	int					z;
	int					pos;
	int					nbr_line;
}						t_fdf;

#endif
