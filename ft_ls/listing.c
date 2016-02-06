/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:48:02 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/07 00:39:43 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dir_size(char *str)
{
		struct dirent	*d;
		DIR				*dir;
		int				i;
		
		i = 0;
		if (!(dir = opendir(str)))
			return (0);
		while ((d = readdir(dir)))
			i++;
		return (i);
}
char	**ft_dir_list(char *str)
{
		struct dirent	*d;
		DIR				*dir;
		int				i;
		char			**tab;

		i = 0;
		if (!(dir = opendir(str)))
		{
				ft_putendl(str);
				exit(EXIT_FAILURE);
		}
		tab = malloc(sizeof(char *) * ft_dir_size(str) + 1);
		while ((d = readdir(dir)))
		{
				if (d->d_name[0] != '.')
				{
					tab[i] = ft_strdup(d->d_name);
					i++;
				}
		}
		tab[i] = NULL;
		tab = ft_sorted_tab(tab);
		return (tab);
}
