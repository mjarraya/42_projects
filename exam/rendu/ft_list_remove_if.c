/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:13:42 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/01 11:28:53 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;

	list = *begin_list;
	while (list)
	{
		if ((*cmp)(list->data, data_ref))
		{
			list->next = list->next->next;
			free (list);
		}
		list = list->next;
	}
}
