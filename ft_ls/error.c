/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:24:46 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:06:27 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_argfiles(t_optlst *opts, t_file *file, t_file *before,
		t_file *tmp)
{
	int		i;

	init_list(&tmp);
	init_list(&before);
	init_list(&file);
	before = file;
	i = 0;
	while (i < ft_tablen(opts->files))
	{
		before = ft_putinfo(before, opts->files[i], ".");
		tmp = before;
		before = new_link(before->next, before);
		i++;
	}
	tmp->next = NULL;
	file = ft_sort_opts_files(opts, file);
	print_dir(file, opts);
	if (opts->elem[0])
		ft_putchar('\n');
	ft_free_list(file);
}

t_optlst	*check_err_file(t_optlst *opts)
{
	if (opts->ba != 0)
	{
		if (opts->elem[0])
		{
			opts->elem = ft_sorted_tab(opts->elem);
			if (opts->t == 1)
				opts->elem = ft_sorted_tab_time(opts->elem);
			if (opts->r == 1)
				opts->elem = ft_sorted_tab_rev(opts->elem);
		}
		if (opts->invalid[0])
			print_invalid(opts);
		if (opts->files[0])
		{
			opts->files = ft_sorted_tab(opts->files);
			if (opts->r == 1)
				opts->files = ft_sorted_tab_rev(opts->files);
			if (opts->t == 1)
				opts->files = ft_sorted_tab_time(opts->files);
			ft_argfiles(opts, NULL, NULL, NULL);
		}
	}
	return (opts);
}

void		no_arg(t_optlst *opts, t_file *file, DIR *directory)
{
	char	*path;
	t_file	*begin;

	directory = opendir(".");
	file = ft_ls(".", directory, opts);
	begin = file;
	print_dir(file, opts);
	if (opts->ur == 1)
	{
		path = ft_strjoin(".", "/");
		ft_lsrecu(directory, opts, file, path);
	}
}
