/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 21:05:16 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/20 21:05:17 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*split;
	char	**tab;
	int		i;
	
	if (argc != 2)
		return (1);
	i = 0;
	split = ft_split(ft_read(argv[1]));
	tab = ft_strsplit(split, '\n');
	while (tab[i])
	{
		printf("%s\n", ft_shift(tab[i]));
		i++;
	}
	return (0);
}