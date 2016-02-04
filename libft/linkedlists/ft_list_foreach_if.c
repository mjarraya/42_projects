/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:59:07 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/03 11:02:41 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*list;

	if (!begin_list)
		return ;
	list = begin_list;
	while (list)
	{
		if ((cmp)(list->data, data_ref) == 0)
			f(list->data);
		list = list->next;
	}
}
