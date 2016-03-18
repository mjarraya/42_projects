/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:27:41 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/18 20:08:09 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (cnt < 2)
	{
		ft_putendl_fd("Carte invalide", 2);
		exit(1);
	}
	return (cnt);
}

int		ft_get_next_nbr(char *str)
{
	int		i;
	char	*num;

	i = 0;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (!(num = ft_memalloc(sizeof(char) * i + 1)))
		exit(1);
	i = 0;
	while (ft_isdigit(str[i]) && str[i])
	{
		num[i] = str[i];
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
	fdf->val = 0;
	fdf->nbr_col = 0;
	fdf->nbr_line = 0;
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
