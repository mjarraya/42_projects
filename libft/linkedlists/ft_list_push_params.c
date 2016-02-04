/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:36:54 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 16:14:30 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*tmp;
	int	i;

	if (ac == 1)
		return NULL;
	i = 2;
	list = ft_create_elem(av[1]);
	list->next = NULL;
	while (i < ac)
	{
		tmp = list;
		list = ft_create_elem(av[i]);
		list->next = tmp;
		i++;
	}
	return (list);
}
