/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:17:58 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/07 00:39:34 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	**tab;
	char	**files;
	t_args	args;
	int		i;

	i = 1;
	args = ft_parse(argc, argv);
	tab = args.elem;
	if (tab[0])
	{
		while (i < argc)
		{
				ft_puttab(ft_dir_list(argv[i]));
				i++;
				if (i < argc)
					ft_putchar ('\n');
		}
	}
//	else
//		ft_ls(".");
	return (0);
}
