/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:34:33 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/19 19:36:52 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

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
			perror("opendir");
			return (0);
		}
		while ((dit = readdir(dip)) != NULL)
		{
			i++;
			if (dit->d_name[0] != '.')
				printf("%s\n", dit->d_name);
		}
		if (closedir(dip) == -1)
		{
			perror("closedir");
			return (0);
		}
		return (0);
	}
	if ((dip = opendir(argv[1])) == NULL)
	{
		perror("opendir");
		return (0);
	}
	while ((dit = readdir(dip)) != NULL)
	{
		i++;
		if (dit->d_name[0] != '.')
			printf("%s\n", dit->d_name);
	}
	if (closedir(dip) == -1)
	{
		perror("closedir");
		return (0);
	}
	return (1);
}
