/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 13:33:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/23 14:28:17 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_fdf_read(char *file, int start)
{
	int		fd;
	char	*line;
	char	*new;
	int		i;
	int		e;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_fdf_error(1);
	new = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		start++;
		new = ft_strjoin(new, line);
		new = ft_strjoin(new, "\n");
		i = ft_count_numbers(line);
		if (start > 1 && i != e)
			ft_fdf_error(0);
		e = i;
		free(line);
	}
	if (start < 2)
		ft_fdf_error(0);
	if (close(fd) == -1)
		ft_fdf_error(2);
	return (new);
}

t_fdf	*ft_fdf_parse(char *map, int i, int x, int y)
{
	t_fdf	*fdf;
	int		pos;

	pos = 0;
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf) * ft_count_numbers(map));
	init_fdf(fdf);
	while (map[++i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf[pos].x = x;
			fdf[pos].y = y;
			fdf[pos].z = map[i - 1] == '-' ? ft_get_next_nbr(&map[i - 1]) * 3 :
			ft_get_next_nbr(&map[i]) * 3;
			fdf[pos].val = fdf[pos].z;
			pos++;
			i++;
			x++;
		}
		if (map[i] == '\n')
			y++;
		x = map[i] == '\n' ? 0 : x;
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
		if (!ft_isdigit(map[i]) && !ft_isspace(map[i]) && map[i] != '-')
		{
			ft_putendl_fd("Carte invalide (nombres et espaces)", 2);
			exit(1);
		}
		i++;
	}
}
