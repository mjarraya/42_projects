/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortedlistinsert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 11:58:30 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/12 12:01:49 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *new)
{
	t_list	*curr;

	if (!begin_list || (*begin_list)->data >= new->data)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
	else
	{
		curr = *begin_list;
		while (curr->next && curr->next->data < new->data)
			curr = curr->next;
		new->next = curr->next;
		curr->next = new;
	}
}
