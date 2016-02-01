/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:45:15 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/01 15:34:38 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		nbword(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
		{
			k++;
			while (ft_isspace(str[i]) == 0 && str[i])
				i++;
		}
		else
			i++;
	}
	return (k);
}

char	*letters(char *str, int index)
{
	int		j;
	int		k;
	char	*dim;

	j = 0;
	k = index;
	while (ft_isspace(str[k]) == 0 && str[k])
		k++;
	if (!(dim = (char *)malloc(k + 1)))
		return (0);
	while (ft_isspace(str[index]) == 0 && str[index])
	{
		dim[j] = str[index];
		j++;
		index++;
	}
	dim[j] = '\0';
	return (dim);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (nbword(str) + 1))))
		return (0);
	while (ft_isspace(str[i]) && str[i])
		i++;
	while (str[i])
	{
		tab[j] = letters(str, i);
		j++;
		while (ft_isspace(str[i]) == 0 && str[i])
			i++;
		while (ft_isspace(str[i]) && str[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

int		main()
{
	printf("%s\n", letters("salut les pede", 6));
}
