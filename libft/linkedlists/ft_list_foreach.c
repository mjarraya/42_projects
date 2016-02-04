/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:19:48 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/03 10:41:27 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list;

	if (!begin_list)
		return ;
	list = begin_list;
	while (list)
	{
		f(list->data);
		list = list->next;
	}
}
