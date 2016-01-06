/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:32:29 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:48:00 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_newline(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_tab	tab_init(int size)
{
	t_tab	tab;
	int		i;

	i = 0;
	tab.tetri = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		tab.tetri[i] = ft_newline(size);
		i++;
	}
	tab.tetri[i] = 0;
	tab.height = size;
	tab.width = size;
	tab.pos_x = 0;
	tab.pos_y = 0;
	return (tab);
}

t_tab	bigger_tab(t_tab tab)
{
	t_tab	new_tab;

	new_tab = tab_init(tab.height + 1);
	return (new_tab);
}

void	tab_free(t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->tetri[i] != '\0')
	{
		ft_strdel(&(tab->tetri[i]));
		i++;
	}
	tab->tetri = NULL;
}

void	print_tab(t_tab tab)
{
	int	i;

	i = 0;
	while (tab.tetri[i])
	{
		ft_putstr(tab.tetri[i]);
		ft_putchar('\n');
		i++;
	}
}
