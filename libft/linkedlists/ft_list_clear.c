/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:15:56 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 16:25:03 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;

	list = *begin_list;
	if (!list)
		return ;
	while (*begin_list)
	{
		*begin_list = list->next->next;
		free(list->next);
		list->next = *begin_list;
	}

}
