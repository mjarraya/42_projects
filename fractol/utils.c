/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:33:56 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 16:42:09 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_random(t_info *info)
{
	char			*random;
	unsigned char	color;

	random = ft_memalloc(1);
	color = (unsigned char)random;
	info->r[0] = color;
	random = ft_memalloc(1);
	color = (unsigned char)random;
	info->r[1] = color;
	random = ft_memalloc(1);
	color = (unsigned char)random;
	info->r[2] = color;
	random = ft_memalloc(1);
	color = (unsigned char)random;
	info->r[3] = color;
	random = ft_memalloc(1);
	color = (unsigned char)random;
	info->r[4] = color;
}

int		ft_strcmp_case(char *str, char *str2)
{
	int		i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (ft_strcmp(str, str2));
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
