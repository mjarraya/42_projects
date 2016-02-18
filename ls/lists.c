/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 02:28:29 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 02:28:31 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_t_files_push_back(t_files **begin_list, t_files *new)
{
	t_files	*list;

	if (!begin_list)
		*begin_list = new;
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

void	ft_t_filescat(t_files *list, t_files *listnext)
{
	t_files	*tmp;

	tmp = list;
	while (list->next)
		list = list->next;
	list->next = listnext;
}
