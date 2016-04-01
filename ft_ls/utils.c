/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:47:48 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:38:24 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_is_dir(char *path)
{
	if (opendir(path) != NULL)
		return (0);
	else
		return (1);
}

int			ft_is_file(char *filename)
{
	struct stat	st;

	return (stat(filename, &st) == 0);
}

t_optlst	*ft_link(char **argv, t_optlst *opts)
{
	opts->files[opts->cf] = ft_strdup(argv[opts->ba]);
	opts->cf++;
	return (opts);
}

void		ft_putnbrendl(int nbr)
{
	ft_putnbr(nbr);
	ft_putchar('\n');
}

int			ft_count_block(t_file *file)
{
	t_file	*tmp;
	int		block;

	block = 0;
	tmp = file;
	while (tmp)
	{
		block += tmp->blocks;
		tmp = tmp->next;
	}
	return (block);
}
