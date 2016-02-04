/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:17:58 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/04 16:40:10 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_str_swap(char *s1, char *s2)
{
	char	*tmp;
	int		i1;
	int		i2;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	if (i1 > i2)
		tmp = (char *)ft_memalloc(sizeof(char) * i1 + 1);
	else
		tmp = (char *)ft_memalloc(sizeof(char) * i2 + 1);
	ft_strcpy(tmp, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, tmp);
}

char	**ft_sorted_tab(char **tab)
{
	int		i;
	int		swap;

	i = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_str_swap(tab[i], tab[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
	return (tab);
}

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
