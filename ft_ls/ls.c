/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:17:58 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/30 16:54:39 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

void	ft_opt_error(char c)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ./ft_ls [-Ralrt] [file ...]", 2);
}

int		ft_is_opt(char c)
{
	if (c == 'R' || c == 'l' || c == 'a' || c == 'r' || c == 't')
		return (1);
	return (0);
}

void	ft_init_opt(t_optlst *opts)
{
	opts->flagur = 0;
	opts->flagr = 0;
	opts->flagl = 0;
	opts->flagt = 0;
	opts->flaga = 0;
}

void	ft_set_opt(t_optlst *opts, char c)
{
	if (c == 'R')
		opts->flagur = 1;
	if (c == 'l')
		opts->flagl = 1;
	if (c == 'a')
		opts->flaga = 1;
	if (c == 'r')
		opts->flagr = 1;
	if (c == 't')
		opts->flagt = 1;
}

t_files	*ft_create_file(char *name, char *dir, int e)
{
	t_files	*file;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	tmp = ft_strjoin(tmp, name);
	file = ft_memalloc(sizeof(t_files));
	file->name = ft_strdup(name);
	file->dir = ft_strdup(dir);
	if (e == FICH)
		if (lstat(tmp, file->stat) == -1)
			perror(tmp);
	file->next = NULL;
	return (file);
}

void	ft_push_front(t_files **files, t_files *new)
{
	new->next = *files;
	*files = new;
}

void	ft_push(t_files *files, t_files *new)
{
	t_files	*tmp;

	while (files->next)
	{
		if (ft_strcmp(files->next->name, new->name) < 0)
		{
			tmp = files->next->next;
			files->next = new;
			new->next = tmp;
			return ;
		}
		files = files->next;
	}
	files->next = new;
}

void	ft_parse_files(int i, char **argv, t_files **files)
{
	if (!ft_strcmp(argv[i], "--"))
		i++;
	*files = ft_create_file(argv[i], "", ARG);
	while (argv[i++])
	{
		if (ft_strcmp((*files)->name, argv[i]) < 0)
			ft_push_front(files, ft_create_file(argv[i], "", ARG));
		else
			ft_push(*files, ft_create_file(argv[i], "", ARG));
	}
}

t_optlst	ft_parse_opts(int argc, char **argv, t_files **files)
{
	int			i;
	int			j;
	t_optlst	opts;

	argc = 0;
	i = 1;
	j = 1;
	ft_init_opt(&opts);
	while (argv[i] && argv[i][0] == '-')
	{
		ft_putendl(argv[i]);
		if (!ft_strcmp(argv[i], "--"))
			break ;
		while (argv[i][j] && argv[i][0] == '-')
		{
			if (ft_is_opt(argv[i][j]))
				ft_set_opt(&opts, argv[i][j]);
			else
				ft_opt_error(argv[i][j]);
			j++;
		}
		i++;
	}
	ft_parse_files(i, argv, files);
	return (opts);
}

int		main(int argc, char **argv)
{
	t_optlst	opts;
	t_files		*files;

	files = NULL;
	opts = ft_parse_opts(argc, argv, &files);
	return (0);
}
