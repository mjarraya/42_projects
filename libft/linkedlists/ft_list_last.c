/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:31:22 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 15:36:36 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*last;

	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	last = begin_list;
	return (last);
}
