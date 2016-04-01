/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:52:51 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:06:46 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	n_head_n_end(t_file ***nhead, t_file ***n_end,
		t_file **tail, t_file **pivot)
{
	if (!(**nhead))
		**nhead = *pivot;
	**n_end = *tail;
}

t_file	*get_tail(t_file *cur)
{
	while (cur && cur->next)
		cur = cur->next;
	return (cur);
}

t_file	*new_link(t_file *new_list, t_file *before)
{
	init_list(&new_list);
	before->next = new_list;
	return (new_list);
}

void	ft_free_list(t_file *begin_list)
{
	t_file *tmp;

	while (begin_list->next)
	{
		tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}
}

int		ft_lst_len(t_file *begin_list)
{
	int		i;
	t_file	*newlst;

	i = 0;
	if (!begin_list)
		return (0);
	newlst = begin_list;
	if (!newlst->next)
		return (1);
	while (newlst)
	{
		newlst = newlst->next;
		i++;
	}
	return (i);
}
