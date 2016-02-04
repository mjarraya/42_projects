/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:37:55 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 14:44:01 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;
	
	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
