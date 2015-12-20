/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:51:21 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/02 13:32:18 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (src_cpy <= dst_cpy)
	{
		dst_cpy = dst_cpy + (len - 1);
		src_cpy = src_cpy + (len - 1);
		while (len--)
			*dst_cpy-- = *src_cpy--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
