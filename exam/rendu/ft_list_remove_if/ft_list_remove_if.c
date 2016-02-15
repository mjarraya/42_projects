/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:41:56 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/15 15:05:08 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;
	t_list	*list2;

	while (*begin_list && (cmp)((*begin_list)->data, data_ref) == 0)
	{
		list = *begin_list;
		*begin_list = (*begin_list)->next;
		free(list);
	}
	list2 = *begin_list;
	while (list2 && list2->next)
	{
		if ((cmp)(list2->next->data, data_ref) == 0)
		{
			list = list2->next;
			list2->next = list->next;
			free(list);
		}
		if (list2->next)
			list2 = list2->next;
	}
}
