/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:22:15 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/04 16:23:29 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_swap(char *s1, char *s2)
{
	char	*tmp;
	int		i1;
	int		i2;
	
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	if (i1 > i2)
		tmp = (char *)ft_memalloc(sizeof(char) * (i1 + 1));
	else
		tmp = (char *)ft_memalloc(sizeof(char) * (i2 + 1));
	ft_strcpy(tmp, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, tmp);
}
