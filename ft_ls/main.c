/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:17:58 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/06 14:19:47 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	**tab;
	t_args	args;
	int		i;

	i = 0;
	args = ft_parse(argc, argv);
	tab = args.elem;
	if (tab[0])
	{
		tab = ft_sorted_tab(tab);
		ft_puttab(tab);
	}
	/*else
		ft_list(".", args);*/
	return (0);
}
