/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggersq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:27:31 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/23 10:27:33 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*ft_biggersq(char *split, int size)
{
	char	*str;
	int		i;
	int		j;

	if (!(str = (char *)malloc(ft_strlen(split) + 2 * size)))
		return (NULL);
	i = 0;
	j = 0;
	while (split[j] != '\n')
	{
		if ((i + 1) % size == 0)
		{
			str[i] = '.'; // derniere colonne
			i++;
			str[i] = split[j];
		}
		else
			str[i] = split[j];
		i++;
		j++;
	}
	str[i] = '.'; // derniere case de l'avant derniere ligne
	j = 0;
	while (j < size)
	{
		str[i + 1] = '.'; // derniere ligne
		i++;
		j++;
	}
	str[i + 1] = '\0';
	return (str);
}
