/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:21:39 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 06:44:01 by mjarraya         ###   ########.fr       */
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
		cont = malloc(sizeof(char *) + 1);
		cont[0] = ft_strdup(path);
		cont[1] = NULL;
		closedir(dir);
		return (cont);
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

int		main(int ac, char **argv)
{
	char	**tab;

	ft_puttab(ft_sorted_tab(ft_dir_cont(argv[1])));
}
