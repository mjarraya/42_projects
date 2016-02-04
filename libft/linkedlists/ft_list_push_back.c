/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:05:52 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 15:20:36 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;
	
	if (!begin_list)
		return ;
	list = *begin_list;
	while (list->next)
		list = list->next;
	list->next = ft_create_elem(data);
}
