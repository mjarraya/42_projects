/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:51:09 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:44:30 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puttime(t_stat filestats, t_file **file)
{
	(*file)->laccess = filestats.st_atimespec;
	(*file)->blocks = filestats.st_blocks;
	(*file)->ldatamod = filestats.st_mtimespec;
	(*file)->lstatch = filestats.st_ctimespec;
	(*file)->birthtime = filestats.st_birthtimespec;
}

void	ft_fill_major(t_stat filestats, t_file **file)
{
	if ((*file)->type == 'c' || (*file)->type == 'b')
	{
		(*file)->major = (int)major(filestats.st_rdev);
		(*file)->minor = (int)minor(filestats.st_rdev);
	}
}
