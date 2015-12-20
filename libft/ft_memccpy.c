/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:26:26 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/01 17:29:19 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		if (src_cpy[i] == (unsigned char)c)
			return (dst_cpy + i + 1);
		i++;
	}
	return (NULL);
}
