/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 13:33:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/15 20:03:22 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	*ft_fdf_read(char *file)
{
	int		fd;
	char	*line;
	char	*new;
	char	*tmp;

	fd = open(file, O_RDONLY);
	new = ft_memalloc(1);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = new;
		new = ft_strjoin(new, line);
		free(tmp);
		tmp = new;
		new = ft_strjoin(new, "\n");
		free(line);
		free(tmp);
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
	num = ft_memalloc(sizeof(char) * i + 1);
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
	fdf->nbr_col = 0;
	fdf->nbr_line = 0;
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
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf) * ft_count_numbers(map));
	while (map[i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf[pos].x = (x + 10) * 10;
			fdf[pos].y = (y + 10) * 10;
			fdf[pos].z = ft_get_next_nbr(&map[i]) * 2;
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
	fdf[0].nbr_col = x;
	fdf[0].pos = pos;
	return (fdf);
}

t_fdf	*ft_max_x(char *map, t_fdf *fdf)
{
	int		i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf->nbr_col++;
			while (ft_isdigit(map[i]) && map[i])
				i++;
		}
		else
			i++;
	}
	return (fdf);
}

int	ft_key_funct(int keycode, t_fdf *info)
{
	if (keycode == 53)
		exit(0);
//	printf("keyevent %d\n", keycode);
	return (0);
}

t_fdf	*ft_3d_to_2d(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf[0].pos)
	{
		if (fdf[i].z > 0)
		{
			fdf[i].x = fdf[i].x - fdf[i].z + 5;
			fdf[i].y = fdf[i].y - fdf[i].z + 5;
		}
		i++;
	}
	return (fdf);
}

int	ft_line_trace(t_fdf *info, t_fdf i, t_fdf f)
{
	int dx;
	int	dy;
	int	sx;
	int	sy;
	int	tab[2];

	dx = f.x < i.x ? i.x - f.x : f.x - i.x;
	dy = f.y < i.y ? i.y - f.y : f.y - i.y;
	sx = i.x < f.x ? 1 : -1;
	sy = i.y < f.y ? 1 : -1;
	tab[0] = (dx > dy ? dx : -dy) / 2;
	while (42)
	{
		mlx_pixel_put(info->mlx, info->win, i.x, i.y, 0xFFFFFF);
		if (i.x == f.x && i.y == f.y)
			break ;
		tab[1] = tab[0];
		if (tab[1] > -dx && (tab[0] -= dy))
			i.x += sx;
		if (tab[1] < dy && (tab[0] += dx))
			i.y += sy;
	}
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

	info = ft_memalloc(sizeof(t_fdf));
	map = ft_fdf_read(argv[1]);
	fdf = ft_fdf_parse(map);
	fdf = ft_max_x(map, fdf);
	fdf = ft_3d_to_2d(fdf);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 600, "FDF\n");
	info->mlx = mlx;
	info->win = win;
	i = 0;
	while (i < fdf[0].pos)
	{
		if (i % fdf->nbr_col != 0)
			ft_line_trace(info, fdf[i - 1], fdf[i]);
		if (i + fdf->nbr_col < fdf[0].pos)
			ft_line_trace(info, fdf[i], fdf[i + fdf->nbr_col]);
	//	printf("point %d, x = %d, y = %d, z = %d\n", i, fdf[i].x, fdf[i].y, fdf[i].z);
		if (fdf[i].z > 0)
			mlx_pixel_put(info->mlx, info->win, fdf[i].x, fdf[i].y, 0xFF00FF);
		else
			mlx_pixel_put(info->mlx, info->win, fdf[i].x, fdf[i].y, 0xFFFFFF);
		i++;
	}
	mlx_pixel_put(info->mlx, info->win, fdf[i].x, fdf[i].y, 0x00FFFFFF);
	mlx_hook(win, 2, 0, ft_key_funct, info);
	mlx_loop(mlx);
	return (0);
}
