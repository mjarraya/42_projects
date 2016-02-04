/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:09:07 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/03 16:30:53 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void 	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
