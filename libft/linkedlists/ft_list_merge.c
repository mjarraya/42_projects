/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:59:57 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/03 12:27:56 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	if (!begin_list1 || !begin_list2)
		return ;
	list = *begin_list1;
	while (list->next)
		list = list->next;
	list->next = begin_list2;
}
