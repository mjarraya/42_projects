/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:21:39 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 22:16:50 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include "ft_ls.h"

char	**ft_dir_cont(char *path)
{
	int				len;
	struct dirent	*ent;
	DIR				*dir;
	char			**cont;
	int				i;

	if (!(dir = opendir(path)) && errno == ENOTDIR)
	{
		if (errno == ENOTDIR)
		{
			cont = malloc(sizeof(char *) + 1);
			cont[0] = ft_strdup(path);
			cont[1] = NULL;
			return (cont);
		}
		else
			perror(path);
	}
	len = 0;
	while ((ent = readdir(dir)))
		len++;
	i = 0;
	ent = NULL;
	dir = opendir(path);
	cont = malloc(sizeof(char *) * (len + 1));
	while ((ent = readdir(dir)))
		cont[i++] = ft_strdup(ent->d_name);
	cont[len] = NULL;
	closedir(dir);
	return (cont);
}
/*
void	get_stat(char *filename, char *dirname)
{
	struct stat	buf;
	char		*path;

	path = ft_strjoin(dirname, "/");
	path = ft_strjoin(path, filename);
	if (stat(path, &buf) == -1)
		perror(filename);
	else

}
*/
int		main(int argc, char **argv)
{
	char	**tab;
	t_args	args;
	int		i;

	i = 0;
	args = ft_parse(argc, argv);
	ft_sorted_tab(args.elem);
	while (args.elem[i])
	{
		ft_puttab(ft_sorted_tab(ft_dir_cont(args.elem[i++])));
	}
}
