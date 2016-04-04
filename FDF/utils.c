/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:27:41 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/31 12:58:13 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_error(int e)
{
	if (e == 0)
	{
		ft_putendl_fd("Carte invalide", 2);
		exit(1);
	}
	if (e == 1)
	{
		ft_putendl_fd("open error()", 2);
		exit(1);
	}
	if (e == 2)
	{
		ft_putendl_fd("close error()", 2);
		exit(1);
	}
	if (e == 3)
	{
		ft_putendl_fd("Carte invalide (-100 < altitude < 100)", 2);
		exit(1);
	}
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
		else
			i++;
	}
	if (cnt < 2)
	{
		ft_putendl_fd("Carte invalide (min: 2 coord.)", 2);
		exit(1);
	}
	return (cnt);
}

#include <stdio.h>

int		ft_get_next_nbr(char *str)
{
	int		i;
	char	*num;

	i = 0;
	if (str[0] == '-')
		i++;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (!(num = ft_memalloc(sizeof(char) * i + 1)))
		exit(1);
	i = 0;
	if (str[0] == '-')
	{
		num[i] = '-';
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		num[i] = str[i];
		i++;
	}
	num[i] = '\0';
	if (ft_atoi(num) > 100 || ft_atoi(num) < -100)
		ft_fdf_error(3);
	return (ft_atoi(num));
}

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->pos = 0;
	fdf->val = 0;
	fdf->n_col = 0;
}

t_fdf	*ft_max_x(char *map, t_fdf *fdf)
{
	int		i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf->n_col++;
			while (ft_isdigit(map[i]) && map[i])
				i++;
		}
		else
			i++;
	}
	return (fdf);
}
