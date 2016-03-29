/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:55:03 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 16:49:42 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		restart_fract(t_fract *fract, t_info *info)
{
	mlx_destroy_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, 800, 800);
	info->img_data = mlx_get_data_addr(info->img, &info->nbit, &info->line,
	&info->endian);
	if (info->f == 1)
		ft_mbrot(fract, info);
	if (info->f == 2)
		ft_julia(fract, info);
	if (info->f == 3)
		ft_bship(fract, info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_string_put(info->mlx, info->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(info->mlx, info->win, 35, 55, 0xFFFFFF,
		"Space to pause and zoom (mouse scroll)");
	return (0);
}

void	put_pixel_to_img(t_fract *m, int x, int y, t_info *info)
{
	if (!ft_strcmp_case(info->color, "reg") && info->f == 3)
		put_pixel_to_img_burn(m, x, y, info);
	else if (!ft_strcmp_case(info->color, "blue")
	|| !ft_strcmp_case(info->color, "reg"))
		put_pixel_to_img_blue(m, x, y, info);
	else if (!ft_strcmp_case(info->color, "red"))
		put_pixel_to_img_burn(m, x, y, info);
	else if (!ft_strcmp_case(info->color, "orange"))
		put_pixel_to_img_orange(m, x, y, info);
	else if (!ft_strcmp_case(info->color, "random"))
		put_pixel_to_img_rand(m, x, y, info);
	else if (!ft_strcmp_case(info->color, "bw"))
		put_pixel_to_img_bw(m, x, y, info);
}

int		ft_select_fract(int choice, t_info *info)
{
	t_fract	*fract;

	if (choice == 1)
		fract = ft_mbrot_init();
	if (choice == 2)
		fract = ft_julia_init();
	if (choice == 3)
		fract = ft_bship_init();
	info->fract = fract;
	info->img = mlx_new_image(info->mlx, 800, 800);
	info->img_data = mlx_get_data_addr(info->img, &info->nbit, &info->line,
	&info->endian);
	info->deca_nbit = info->nbit >> 3;
	if (choice == 1)
		ft_mbrot(fract, info);
	if (choice == 2)
		ft_julia(fract, info);
	if (choice == 3)
		ft_bship(fract, info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	return (choice);
}

void	ft_fractol(char *file, t_info *info)
{
	int		ret;

	if (!(ft_fractol_verif(file)))
		ft_fractol_err(0);
	if (!(info->color))
		info->color = ft_strdup("reg");
	if (!ft_strcmp_case(info->color, "random"))
		init_random(info);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 800, 800, file);
	ret = ft_fractol_verif(file);
	ret = ft_select_fract(ret, info);
	mlx_string_put(info->mlx, info->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(info->mlx, info->win, 35, 55, 0xFFFFFF,
		"Space to pause and zoom (mouse scroll)");
	mlx_hook(info->win, 17, 0, ft_exit, info);
	if (ret != 3 && ret != 4)
		mlx_hook(info->win, 6, 0, ft_mouse_funct, info);
	mlx_hook(info->win, 4, 0, ft_mouse_scroll, info);
	mlx_hook(info->win, 2, 0, ft_key_funct, info);
	mlx_loop(info->mlx);
}

int		main(int argc, char **argv)
{
	t_info	*info;

	info = ft_memalloc(sizeof(t_info));
	if (argc > 3 || argc < 2)
		ft_fractol_err(0);
	if (argc == 3)
	{
		if (!ft_fractol_verif_col(argv[2]))
			ft_fractol_err(1);
		info->color = ft_strdup(argv[2]);
		ft_fractol(argv[1], info);
	}
	if (argc == 2)
		ft_fractol(argv[1], info);
	return (0);
}
