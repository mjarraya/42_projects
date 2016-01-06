/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:29:29 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/01 17:28:51 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = (*f)(s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
