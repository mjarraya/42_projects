/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 13:33:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/18 19:29:01 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_fdf_read(char *file)
{
	int		fd;
	char	*line;
	char	*new;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("open error()", 2);
		exit(1);
	}
	new = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		new = ft_strjoin(new, line);
		new = ft_strjoin(new, "\n");
		free(line);
	}
	if (close(fd) == -1)
	{
		ft_putendl_fd("close error()", 2);
		exit(0);
	}
	return (new);
}

t_fdf	*ft_fdf_parse(char *map, int i, int x, int y)
{
	t_fdf	*fdf;
	int		pos;

	pos = 0;
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf) * ft_count_numbers(map));
	init_fdf(fdf);
	while (map[i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf[pos].x = x;
			fdf[pos].y = y;
			fdf[pos].z = ft_get_next_nbr(&map[i]) * 3;
			fdf[pos].val = fdf[pos].z;
			pos++;
			i++;
			x++;
		}
		if (map[i] == '\n')
			y++;
		x = map[i] == '\n' ? 0 : x;
		i++;
	}
	fdf[0].pos = pos;
	return (fdf);
}

void	ft_verif_fdf(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (i > 180000)
		{
			ft_putendl_fd("Carte invalide", 2);
			exit(1);
		}
		if (!ft_isdigit(map[i]) && !ft_isspace(map[i]))
		{
			ft_putendl_fd("Carte invalide (nombres et espaces)", 2);
			exit(1);
		}
		i++;
	}
}

int		ft_fdf(char *file)
{
	char	*map;
	t_fdf	*fdf;
	t_fdf	*info;

	info = ft_memalloc(sizeof(t_fdf));
	map = ft_fdf_read(file);
	ft_verif_fdf(map);
	fdf = ft_fdf_parse(map, 0, 0, 0);
	fdf = ft_max_x(map, fdf);
	fdf = ft_3d_to_2d(fdf, -1, 0, 0);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1920, 1080, "FDF\n");
	ft_draw_map(fdf, info);
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
