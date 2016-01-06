/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:14:05 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:49:48 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_counttetri(char *s)
{
	int	nb;

	nb = (ft_charcount(s, '#') / 4);
	return (nb);
}

char	*ft_split(char *s)
{
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\n' || (s[i] == '\n' && s[i - 1] == '\n'))
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\n';
	s[j + 1] = '\0';
	return (s);
}

int		ft_checklinelen(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != '\n')
		{
			if (j > 4)
				return (0);
			j++;
			i++;
		}
		i++;
	}
	return (1);
}

int		ft_verif(char *read)
{
	char	*s;

	if (!(s = ft_read(read)))
		return (0);
	if (ft_checklinelen(s) == 0)
		return (0);
	if (ft_validmap(ft_split(s)) == 0)
		return (0);
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	free(tab);
}
