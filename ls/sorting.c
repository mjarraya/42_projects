/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 03:23:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 03:23:19 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_ascii(t_files **begin_list)
{
	t_files	*curr;
	t_files	*prev;
	t_files	*tmp;
}

void	ft_sort_reverse(t_files **begin_list)
{
	t_files *prev;
	t_files *curr;
	t_files	*next;

	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}

void	ft_sort_time(t_files *begin_list)
{

}

void	ft_sort_size(t_files *begin_list)
{

}
