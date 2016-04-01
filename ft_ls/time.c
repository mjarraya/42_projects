/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:10:33 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:03:46 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_var(t_file **pivot, t_file **end, t_file **cur, t_file **head)
{
	*pivot = *end;
	*cur = *head;
}

void	init_var2(t_file **prev, t_file **tail, t_file **pivot)
{
	*prev = NULL;
	*tail = *pivot;
}

t_file	*partition_sec(t_file *head, t_file *end,
	t_file **nhead, t_file **n_end)
{
	t_file *pivot;
	t_file *prev;
	t_file *cur;
	t_file *tail;
	t_file *tmp;

	init_var(&pivot, &end, &cur, &head);
	init_var2(&prev, &tail, &pivot);
	while (cur != pivot)
	{
		if (c_d_ps(cur, pivot) && cur->ldatamod.tv_sec > pivot->ldatamod.tv_sec)
			if_part(nhead, &cur, &prev);
		else if (cur->ldatamod.tv_sec < pivot->ldatamod.tv_sec)
			part_else(&prev, &cur, &tail, &tmp);
		else if (c_d_pn(cur, pivot) && c_g_pn(cur, pivot))
			if_part(nhead, &cur, &prev);
		else if (c_l_pn(cur, pivot) && c_e_ps(cur, pivot))
			part_else(&prev, &cur, &tail, &tmp);
		else if ((ft_strcmp(cur->dname, pivot->dname) < 0))
			if_part(nhead, &cur, &prev);
		else
			part_else(&prev, &cur, &tail, &tmp);
	}
	n_head_n_end(&nhead, &n_end, &tail, &pivot);
	return (pivot);
}
