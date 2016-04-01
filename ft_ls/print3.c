/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:08:34 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:05:04 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ol(char *tmp)
{
	ft_putchar('\n');
	ft_putstr(tmp);
	ft_putstr(":");
	ft_putchar('\n');
}

void	ft_print_block(t_optlst *opts, char *dirname, t_file *file)
{
	int block;

	block = ft_count_block(file);
	if (block < 0)
		block = 0;
	if (opts->l == 1 && opts->ur == 1)
	{
		if (ft_strcmp(dirname, "."))
		{
			ft_putchar('\n');
			ft_putstr(dirname);
			ft_putstr(":\ntotal ");
			ft_putnbrendl(block);
		}
		else
		{
			ft_putstr("total ");
			ft_putnbrendl(block);
		}
	}
	else if (opts->l == 1)
	{
		ft_putstr("total ");
		ft_putnbrendl(block);
	}
}

void	ft_print_dir_name(char *opts)
{
	ft_putstr(opts);
	ft_putendl(":");
}

void	print_dir(t_file *file, t_optlst *opts)
{
	if (!file->dname)
		return ;
	while (file)
	{
		ft_what_print(file, opts);
		file = file->next;
	}
}

void	print_elem(t_optlst *opts, t_file *file, DIR *directory, int i)
{
	char	*path;

	while (opts->elem[++i])
	{
		if (ft_tablen(opts->elem) >= 2 || opts->files[0] || opts->invalid[0])
			ft_print_dir_name(opts->elem[i]);
		if (ft_is_dir(opts->elem[i]) == 1)
			ft_permission_denied(opts->elem[i]);
		else
		{
			directory = opendir(opts->elem[i]);
			file = ft_ls(opts->elem[i], directory, opts);
			print_dir(file, opts);
			if (ft_tablen(opts->elem) >= 2)
				ft_putchar('\n');
			if (opts->ur == 1)
			{
				path = ft_strjoin(opts->elem[i], "/");
				ft_lsrecu(directory, opts, file, path);
			}
		}
	}
}
