/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:07:17 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/02 13:43:22 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	ret = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size)
		ret = ret + i;
	else
		ret = ret + size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, (char *)src, size - ft_strlen(dst) - 1);
	return (ret);
}
