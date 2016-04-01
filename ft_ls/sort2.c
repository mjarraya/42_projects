/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:17:03 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:05:20 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*quick_recur_sec(t_file *head, t_file *end)
{
	t_file *nhead;
	t_file *n_end;
	t_file *pivot;
	t_file *tmp;

	nhead = NULL;
	n_end = NULL;
	if (!head || head == end)
		return (head);
	pivot = partition_sec(head, end, &nhead, &n_end);
	if (nhead != pivot)
	{
		tmp = nhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		nhead = quick_recur_sec(nhead, tmp);
		tmp = get_tail(nhead);
		tmp->next = pivot;
	}
	pivot->next = quick_recur_sec(pivot->next, n_end);
	return (nhead);
}

t_file	*ft_sort_reverse(t_file *begin)
{
	t_file	*prev;
	t_file	*curr;
	t_file	*temp;

	curr = begin->next;
	prev = begin;
	while (begin->next)
		begin = begin->next;
	prev->next = NULL;
	while (curr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return (begin);
}

t_file	*ft_sort_opts(t_optlst *opts, t_file *file)
{
	quick_sort_name(&file);
	if (opts->t == 1)
		quick_sort_sec(&file);
	if (opts->r == 1)
		file = ft_sort_reverse(file);
	return (file);
}

void	rem_null(t_file **file)
{
	t_file **tmp;

	tmp = NULL;
	*tmp = *file;
	while (*file)
	{
		if (!*tmp)
		{
			free(*tmp);
			break ;
		}
		*tmp = (*file)->next;
	}
}

t_file	*ft_sort_opts_files(t_optlst *opts, t_file *file)
{
	quick_sort_name(&file);
	if (opts->t == 1)
		quick_sort_sec(&file);
	if (opts->r == 1)
		file = ft_sort_reverse(file);
	return (file);
}
