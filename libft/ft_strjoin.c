/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:41:40 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/11 15:24:19 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	ptr = (char *)malloc((sizeof(*ptr) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!ptr)
		return (NULL);
	ft_strcat(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}
