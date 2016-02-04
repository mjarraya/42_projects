/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:34:33 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/29 11:25:42 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	DIR				*dip;
	struct dirent	*dit;
	int				i;

	i = 0;
	if (argc < 2)
	{
		if ((dip = opendir(".")) == NULL)
		{
			perror("");
			return (0);
		}
		while ((dit = readdir(dip)) != NULL)
		{
			i++;
			if (dit->d_name[0] != '.')
				ft_putendl(dit->d_name);
		}
		if (closedir(dip) == -1)
		{
			perror("closedir");
			return (0);
		}
		return (1);
	}
	if ((dip = opendir(argv[1])) == NULL)
	{
		ft_putstr("ls: ");
		perror(argv[1]);
		return (0);
	}
	while ((dit = readdir(dip)) != NULL)
	{
		i++;
		if (dit->d_name[0] != '.')
			ft_putendl(dit->d_name);
	}
	if (closedir(dip) == -1)
	{
		perror("closedir");
		return (0);
	}
	return (1);
}
