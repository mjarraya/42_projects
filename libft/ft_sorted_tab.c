/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:23:35 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/06 14:18:38 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sorted_tab(char **tab)
{
	int		i;
	int		j;
	int		len;

	len = ft_tablen(tab);
	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < len)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
				ft_str_swap(tab[j - 1], tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}
