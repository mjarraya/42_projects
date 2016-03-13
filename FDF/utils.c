/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 10:47:50 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/13 11:07:46 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_count_line(t_fdf *fdf, int fd)
{
	char	*line;

	fdf->nbr_line = 0;
	while (get_next_line(fd, &line) > 0)
		(fdf->nbr_line)++;
	close(fd);
}

char	*ft_map_trim(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		if (!ft_isdigit(str[i]))
			str[i] = ' ';
		i++;
	}
	return (str);
}
