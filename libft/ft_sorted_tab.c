/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:23:35 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/04 16:24:46 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
