/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:31:59 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:54:30 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_list(t_file **list)
{
	if (!(*list = (t_file *)ft_memalloc(sizeof(t_file))))
		return ;
	(*list)->dname = NULL;
	(*list)->type = 0;
	(*list)->rights = NULL;
	(*list)->xattributes = 0;
	(*list)->links = 0;
	(*list)->uname = NULL;
	(*list)->gname = NULL;
	(*list)->size = 0;
	(*list)->lnpath = NULL;
	(*list)->l = NULL;
	(*list)->minor = 0;
	(*list)->major = 0;
	(*list)->blocks = 0;
	(*list)->denied = 0;
	(*list)->next = NULL;
}

t_file	*ls_hidd(t_file *before, DIR *directory, t_dir *dirstruct, char *dname)
{
	t_file	*tmp;

	init_list(&tmp);
	while ((dirstruct = readdir(directory)))
	{
		if (dirstruct->d_name[0] != '.')
		{
			before = ft_putinfo(before, dirstruct->d_name, dname);
			tmp = before;
			before = new_link(before->next, before);
		}
	}
	tmp->next = NULL;
	return (before);
}

t_file	*ls(t_file *before, DIR *directory, t_dir *dirstruct, char *dname)
{
	t_file	*tmp;

	init_list(&tmp);
	while ((dirstruct = readdir(directory)))
	{
		before = ft_putinfo(before, dirstruct->d_name, dname);
		tmp = before;
		before = new_link(before->next, before);
	}
	tmp->next = NULL;
	return (before);
}

t_file	*ft_ls(char *dirname, DIR *directory, t_optlst *opts)
{
	t_dir	*dirstruct;
	t_file	*file;
	t_file	*before;
	t_file	*begin;
	int		block;

	init_list(&before);
	init_list(&begin);
	init_list(&file);
	dirstruct = NULL;
	before = file;
	block = 0;
	if (opts->a == 0)
		before = ls_hidd(before, directory, dirstruct, dirname);
	else
		before = ls(before, directory, dirstruct, dirname);
	ft_print_block(opts, dirname, file);
	if (file->next)
		file = ft_sort_opts(opts, file);
	begin = file;
	closedir(directory);
	return (begin);
}
