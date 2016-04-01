/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:58:59 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 16:00:34 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_no_directory(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	ft_print_denied_recu(t_file *file, char *tmp)
{
	ft_putchar('\n');
	ft_putstr(tmp);
	ft_putendl(":");
	if (ft_is_dir(file->dname) == 1)
		ft_permission_denied(tmp);
	else
		ft_no_directory(file->dname);
}

void	ft_permission_denied(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": Permission denied", 2);
}
