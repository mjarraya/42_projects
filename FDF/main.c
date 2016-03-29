/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:43:49 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/23 14:28:25 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(void *param)
{
	t_fdf	*info;

	info = param;
	exit(1);
}

int		ft_fdf(char *file)
{
	char	*map;
	t_fdf	*fdf;
	t_fdf	*info;

	info = ft_memalloc(sizeof(t_fdf));
	map = ft_fdf_read(file, 0);
	ft_verif_fdf(map);
	fdf = ft_fdf_parse(map, -1, 0, 0);
	fdf = ft_max_x(map, fdf);
	fdf = ft_3d_to_2d(fdf, -1, 0, 0);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1920, 1080, "FDF\n");
	ft_draw_map(fdf, info);
	mlx_string_put(info->mlx, info->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_hook(info->win, 17, 0, ft_exit, info);
	mlx_hook(info->win, 2, 0, ft_key_funct, info);
	mlx_loop(info->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fdf [map]", 2);
		return (0);
	}
	ft_fdf(argv[1]);
	return (0);
}
