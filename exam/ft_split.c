/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:09:00 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/01 19:18:18 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (is_space(str[i]) == 0 && 
				(is_space(str[i + 1]) == 1 || str[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

char	*letters(char *str, int pos)
{
	int		i;
	int		j;
	char	*word;

	i = pos;
	j = 0;
	while (is_space(str[i]) == 0 && str[i])
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (is_space(str[pos]) == 0 && str[pos])
	{
		word[j] = str[pos];
		j++;
		pos++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (is_space(str[i]) == 1 && str[i])
		i++;
	while (str[i])
	{
		tab[j] = letters(str, i);
		j++;
		while (is_space(str[i]) == 0 && str[i])
			i++;
		while (is_space(str[i]) == 1 && str[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
