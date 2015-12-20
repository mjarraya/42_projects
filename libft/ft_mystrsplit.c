/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:59:18 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/02 14:50:16 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;
	size_t	i;
	size_t	cnt;

	cnt = 0;
	len = ft_wordcount(s, c);
	if (len == 0)
		cnt = 1;
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s && cnt++ <= ft_wordcount(s, c))
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		tab[i++] = ft_strndup(s - len, len);
	}
	return (tab);
}
