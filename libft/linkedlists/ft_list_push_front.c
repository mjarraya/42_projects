/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:20:40 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 15:28:32 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;
	
	if (!begin_list)
		return ;
	list = ft_create_elem(data);
	list->next = *begin_list;
	*begin_list = list;
}
