/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:53:30 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:42:50 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnstrcolor(int size, char *str, char *color)
{
	int	len;

	len = ft_strlen(str);
	while (size - len >= 0)
	{
		ft_putchar(' ');
		size--;
	}
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(RESET);
}

void	ft_putnnbr(int size, int nbr)
{
	int	len;

	len = ft_cnumber(nbr);
	while (size - len >= 0)
	{
		ft_putchar(' ');
		size--;
	}
	ft_putnbr(nbr);
}

void	ft_print_time(t_file *file, t_optlst *opts)
{
	if (opts->t == 0 && ((file->ldatamod.tv_sec <= (time(NULL) + 3600) &&
					(file->ldatamod.tv_sec + 15778800) >= time(NULL))))
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 12));
	else if (opts->t == 0)
	{
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 7));
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[19], 5));
	}
	if (opts->t == 1 && ((file->ldatamod.tv_sec <= (time(NULL) + 3600) &&
					(file->ldatamod.tv_sec + 15778800) >= time(NULL))))
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 12));
	else if (opts->t == 1)
	{
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 7));
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[19], 5));
	}
	ft_putchar(' ');
}

void	ft_what_print(t_file *file, t_optlst *opts)
{
	if (opts->l == 1 && opts->g == 1)
		ft_printinfo_color(file, opts);
	else if (opts->l == 1)
		ft_printinfo(file, opts);
	else
		ft_simpleprint(file, opts);
}

void	ft_simpleprint(t_file *file, t_optlst *opts)
{
	if (file->denied == 1)
	{
		ft_permission_denied(file->dname);
		return ;
	}
	if (opts->g == 1)
		ft_putnstrcolor(0, file->dname, color(file));
	else
		ft_putstr(file->dname);
	ft_putchar('\n');
}
