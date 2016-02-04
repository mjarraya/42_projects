/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:28:10 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/04 15:48:19 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);

void	ft_list_swap(t_list *a, t_list *b)
{
	t_list *tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*sorted;
	int		swap;
	void	*tmp;

	if (!begin_list)
		return ;
	sorted = *begin_list;
	swap = 1;
	while (swap)
	{
		swap = 0;
		sorted = *begin_list;
		while (sorted->next)
		{
			if ((cmp)(sorted->data, sorted->next->data) > 0)
			{
				ft_list_swap(sorted, sorted->next);
				swap = 1;
			}
			sorted = sorted->next;
		}
	}
}
