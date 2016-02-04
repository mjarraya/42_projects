/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:18:11 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/01 17:27:20 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc((sizeof(*ptr) * size));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return ((void *)ptr);
}
