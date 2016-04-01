/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:07:48 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 16:01:15 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_recu(t_file **file, char **tmp, t_file **begin)
{
	*tmp = NULL;
	*begin = *file;
	if ((*file)->dname == NULL)
		*file = NULL;
}

void	ft_print_dir_and_tmp(t_file **newfile, t_optlst *opts, char **tmp)
{
	print_dir(*newfile, opts);
	*tmp = ft_strjoin(*tmp, "/");
}

void	ft_strclr_and_file_next(char **tmp, t_file **file)
{
	ft_strclr(*tmp);
	*file = (*file)->next;
}

int		ft_hidden(t_file *file)
{
	if (ft_strcmp(file->dname, ".") && ft_strcmp(file->dname, ".."))
		return (1);
	return (0);
}

void	ft_lsrecu(DIR *directory, t_optlst *opts, t_file *file, char *path)
{
	DIR		*newdir;
	t_file	*newfile;
	t_file	*begin;
	char	*tmp;

	init_recu(&file, &tmp, &begin);
	while (file)
	{
		tmp = ft_strjoin(path, file->dname);
		if (file->type == 'd' && ft_hidden(file) == 1 && file->type != 'l')
		{
			if ((newdir = opendir(tmp)))
			{
				newfile = ft_ls(tmp, newdir, opts);
				if (opts->l == 0)
					ft_print_ol(tmp);
				ft_print_dir_and_tmp(&newfile, opts, &tmp);
				ft_lsrecu(directory, opts, newfile, tmp);
			}
			else
				ft_print_denied_recu(file, tmp);
		}
		ft_strclr_and_file_next(&tmp, &file);
	}
	ft_free_list(begin);
}
