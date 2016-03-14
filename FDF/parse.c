/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 13:33:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/14 17:36:38 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	*ft_fdf_read(char *file)
{
	int		fd;
	char	*line;
	char	*new;

	fd = open(file, O_RDONLY);
	new = "";
	while (get_next_line(fd, &line) > 0)
	{
		new = ft_strjoin(new, line);
		new = ft_strjoin(new, "\n");
		free(line);
	}
	return (new);
}
int		ft_count_numbers(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			cnt++;
			while (ft_isdigit(str[i]) && str[i])
				i++;
		}
		i++;
	}
	return (cnt);
}
int		ft_get_next_nbr(char *s)
{
	int		i;
	char	*num;

	i = 0;
	while (ft_isdigit(s[i]) && s[i])
		i++;
	num = malloc(sizeof(char) * i + 1);
	i = 0;
	while (ft_isdigit(s[i]) && s[i])
	{
		num[i] = s[i];
		i++;
	}
	num[i] = '\0';
	return (ft_atoi(num));
}

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->pos = 0;
}

t_fdf	*ft_fdf_parse(char *map)
{
	int			i;
	t_fdf		*fdf;
	int			y;
	int	pos;
	int			x;

	x = 0;
	pos = 0;
	i = 0;
	y = 0;
	fdf = (t_fdf *)malloc(sizeof(t_fdf) * ft_count_numbers(map));
	while (map[i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf[pos].x = (x + 10) * 10;
			fdf[pos].y = (y + 10) * 10;
			fdf[pos].z = ft_get_next_nbr(&map[i]);
			pos++;
			i++;
			x++;
		}
		if (map[i] == '\n')
		{
			y++;
			x = 0;
		}
		i++;
	}
	fdf[0].pos = pos;
	return (fdf);
}

int	ft_key_funct(int keycode, t_fdf *info)
{
	if (keycode == 53)
		exit(0);
	printf("keyevent %d\n", keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*map;
	int		i;
	t_fdf	*fdf;
	void 	*mlx;
	void 	*win;
	t_fdf	*info;

	info = malloc(sizeof(t_fdf));
	map = ft_fdf_read(argv[1]);
	fdf = ft_fdf_parse(map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FDF\n");
	info->mlx = mlx;
	info->win = win;
	i = 0;
	while (i < fdf[0].pos)
	{
		//fdf[i] = *get_3d(&fdf[i]);
		//printf("point %d, x = %d, y = %d, z = %d\n", i, fdf[i].x, fdf[i].y, fdf[i].z);
		if (fdf[i].z > 0)
			mlx_pixel_put(info->mlx, info->win, fdf[i].x, fdf[i].y, 0xFF0000);
		else
			mlx_pixel_put(info->mlx, info->win, fdf[i].x, fdf[i].y, 0xFFFFFF);
		i++;
	}
	mlx_key_hook(win, ft_key_funct, info);
	mlx_loop(mlx);
	return (0);
}
