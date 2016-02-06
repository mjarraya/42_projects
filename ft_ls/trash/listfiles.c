/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 11:28:24 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/07 00:39:58 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_dir_list(char *str)
{
	DIR				*mydir;
	struct dirent	*myfile;

	if ((mydir = opendir(str)) == NULL)
	{
		perror(str);
		printf("bang\n");
		return ;
	}
	while ((myfile = readdir(mydir)) != NULL)
	{
		if (myfile->d_name[0] != '.')
			ft_putendl(myfile->d_name);
	}
	if (closedir(mydir) == -1)
	{
		perror(str);
		return ;
	}
}

int		main(int argc, char **argv)
{
	int				i;

	i = 1;
	if (argc < 2)
	{
		ft_dir_list(".");
		return (0);
	}
	while (i < argc)
	{
		ft_dir_list(argv[i]);
		if (i < argc - 1)
			ft_putstr("\n");
		i++;
	}
	return (0);
}
