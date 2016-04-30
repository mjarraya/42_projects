/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:35:20 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/08 17:25:25 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		is_space(char c)
{
		if (c == ' ' || c == '\t')
			return (1);
		return (0);
}

int		count_words(char *str)
{
		int		i;
		int		nb;

		nb = 0;
		i = 0;
		while (is_space(str[i]) && str[i])
			i++;
		while (str[i])
		{
				if (is_space(str[i]) == 0)
				{
					nb++;
					while (str[i] && is_space(str[i]) == 0)
						i++;
				}
				else
					i++;
		}
		return (nb);
}

char	*fill_letters(char *str, int pos)
{
		int		i;
		int		j;
		char	*word;

		i = 0;
		j = pos;
		while (str[j] && is_space(str[j]))
			j++;
		word = (char *)malloc(sizeof(char) * (j + 1));
		if (!word)
			return (NULL);
		while (is_space(str[pos]) == 0 && str[pos]) 
		{
			word[i] = str[pos];
			i++;
			pos++;
		}
		word[i] = '\0';
		return (word);
}		

char	**ft_split(char *str)
{
		int		i;
		int		j;
		char	**tab;

		i = 0;
		j = 0;
		tab = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
		if (!tab)
			return (NULL);
		while (is_space(str[i]) && str[i])
			i++;
		while (str[i])
		{
			tab[j] = fill_letters(str, i);
			j++;
			while (is_space(str[i]) == 0 && str[i])
				i++;
			while (is_space(str[i]) && str[i])
				i++;
		}
		tab[j] = NULL;
		return (tab);
}

void	ft_putstr(char *str)
{
		int		i;

		i = 0;
		while (str[i])
		{
				write(1, &str[i], 1);
				i++;
		}
}

int		main(int argc, char **argv)
{
		char	**tab;
		int		i;

		i = 0;
		if (argc != 2)
		{
			write(1, "\n", 1);
			return (0);
		}
		tab = ft_split(argv[1]);
		while (tab[i])
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(tab[i]);
			if (i > 0)
				ft_putstr(" ");
			i--;
		}
		ft_putstr("\n");
		return (0);
}
