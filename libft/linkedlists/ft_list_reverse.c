/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:33:30 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/22 00:03:14 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_reverse(t_list *head)
{
	t_list	*previous;
	t_list	*ptr;
	t_list	*temp;

	ptr = head->next;
	previous = head;
	while (head->next)
		head = head->next;
	previous->next = NULL;
	while (ptr)
	{
		temp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = temp;
	}
	return (head);

}
