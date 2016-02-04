/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:29:29 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/11 15:18:13 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
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
