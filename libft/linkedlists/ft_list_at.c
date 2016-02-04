/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:25:14 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 16:33:25 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*at;
	unsigned int	i;

	i = 1;
	if (!begin_list)
		return (NULL);
	while (begin_list->next && i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	at = begin_list;
	at->next = NULL;
	return (at);
}
