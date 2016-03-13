/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:50:03 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/13 15:05:33 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_fdf	*ft_fill_coord(int z)
{
	t_fdf	*env;

	env = malloc(sizeof(t_fdf));
	env->z = z;
	return (env);
}*/

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

void	init_fdf(t_fdf *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
}

#include <stdio.h>

t_fdf	*ft_parse_values(char *line, t_fdf point, int k, int line_nbr)
{
	int		i;
	int		j;
	int		cnt;
	char	*numb;
	static int	pos;

	pos = -1;
//	init_fdf(&point);
	i = 0;
	k = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			pos++;
			j = 0;
			cnt = 0;
			while (ft_isdigit(line[cnt]) && line[cnt])
				cnt++;
			numb = malloc(sizeof(char) * cnt + 1);
			while (ft_isdigit(line[i]) && line[i])
			{
				numb[j] = line[i];
				i++;
				j++;
			}
			numb[j] = '\0';
			point[pos].z = ft_atoi(numb);
			point[pos].y = k;
			point[pos].x = line_nbr;
			printf("pos = %d, point z = %d, point y = %d, point x = %d\n", pos, point[pos].z, point[pos].y, point[pos].x);
			k++;
		}
		i++;
	}
	return (point);
}

int	ft_fdf_parse(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	int		k;
	int		line_nbr;
	t_fdf	*point;

	line_nbr = 0;
	fd = open(file, O_RDONLY);
	k = 0;
	if (fd == -1)
	{
		ft_putendl_fd("open() error", 2);
		return (1);
	}
	map = "";
	while (get_next_line((int const)fd, &line) > 0)
	{
		k += ft_count_numbers(line);
		map = ft_strjoin(map, line);
		map = ft_strjoin(map, "\n");
		free(line);
	}
	fd = open(file, O_RDONLY);
	point = malloc(sizeof(t_fdf) * k);
	ft_parse_values(line, &point, k, line_nbr);
	printf("point z = %d, point y = %d, point x = %d\n", point[k].z, point[k].y, point[k].x);
	return (0);
}

int	main(int argc, char **argv)
{
	ft_fdf_parse(argv[1]);
	return (0);
}
