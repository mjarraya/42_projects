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

char	*ft_appendsq(char *split, int size)
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
			str[i] = ',';
			i++;
			str[i] = split[j];
		}
		else
			str[i] = split[j];
		i++;
		j++;
	}
	str[i] = ',';
	j = 0;
	while (j < size)
	{
		str[i + 1] = ';';
		i++;
		j++;
	}
	str[i + 1] = '\0';
	return (str);
}

/*
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*split;
	char	**tab;
	int		i;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (1);
	}
	i = 0;
	if (!(split = ft_split(ft_read(argv[1]))))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (ft_validmap(split) == 0)
		ft_putstr("error\n");
	printf("%s\n", split);
	printf("%s\n", ft_appendsq(split, 6));
	return (0);
}
*/