/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 10:47:50 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/14 12:53:18 by mjarraya         ###   ########.fr       */
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
