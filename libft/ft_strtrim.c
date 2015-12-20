/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:10:40 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/01 17:32:58 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*ptr;

	i = 0;
	k = 0;
	while (s[k] != '\0')
		k++;
	while (s[k] == '\0' || s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
		k--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i == ft_strlen(s))
		return (ft_strdup(""));
	ptr = ft_strsub(s, i, (k - i + 1));
	return (ptr);
}
