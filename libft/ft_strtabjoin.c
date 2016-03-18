/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:52:16 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/26 20:04:25 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabjoin(char **tab, char *str)
{
	char	**new;
	int		i;

	i = ft_tablen(tab);
	if (!(new = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	return (new);
}
