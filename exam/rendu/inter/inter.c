/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:21:05 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/22 14:26:20 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		is_intab(char *tab, char c)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int		i;
	int		j;
	int		tabi;
	char	tab[256];

	i = 0;
	tabi = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != s2[j] && s2[j])
			j++;
		if (s1[i] == s2[j])
		{
			if (is_intab(tab, s1[i]) == 0)
			{
				tab[tabi] = s1[i];
				tabi++;
			}
		}
		i++;	
	}
	ft_putstr(tab);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
