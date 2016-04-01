/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:16:46 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:04:55 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	part_else(t_file **prev, t_file **cur, t_file **tail, t_file **tmp)
{
	if (*prev)
		(*prev)->next = (*cur)->next;
	*tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = *cur;
	*tail = *cur;
	*cur = *tmp;
}

void	if_part(t_file **nhead, t_file **cur, t_file **prev)
{
	if (!(*nhead))
		*nhead = *cur;
	*prev = *cur;
	*cur = (*cur)->next;
}

t_file	*partition(t_file *head, t_file *end,
	t_file **nhead, t_file **n_end)
{
	t_file *pivot;
	t_file *prev;
	t_file *cur;
	t_file *tail;
	t_file *tmp;

	pivot = end;
	prev = NULL;
	cur = head;
	tail = pivot;
	while (cur != pivot)
	{
		if (ft_strcmp(cur->dname, pivot->dname) < 0)
			if_part(nhead, &cur, &prev);
		else
			part_else(&prev, &cur, &tail, &tmp);
	}
	if (!(*nhead) && (*nhead = pivot))
		;
	*n_end = tail;
	return (pivot);
}

t_file	*quick_recur(t_file *head, t_file *end)
{
	t_file *nhead;
	t_file *n_end;
	t_file *pivot;
	t_file *tmp;

	nhead = NULL;
	n_end = NULL;
	if (!head || head == end)
		return (head);
	pivot = partition(head, end, &nhead, &n_end);
	if (nhead != pivot)
	{
		tmp = nhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		nhead = quick_recur(nhead, tmp);
		tmp = get_tail(nhead);
		tmp->next = pivot;
	}
	pivot->next = quick_recur(pivot->next, n_end);
	return (nhead);
}

void	quick_sort_name(t_file **head)
{
	*head = quick_recur(*head, get_tail(*head));
	return ;
}
