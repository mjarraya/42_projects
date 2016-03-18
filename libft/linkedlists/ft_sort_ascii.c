/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:03:26 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/22 01:43:30 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] != '\0' || p2[i] != '\0')
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

t_list	*ft_sort_ascii(t_list *head, int (*cmp)())
{
	t_list		*ptr;
	t_list		*previous;
	t_list		*temp;

	ptr = head;
	previous = ptr;
	while (ptr->next)
	{
		if ((cmp)(ptr->data, (ptr->next)->data) > 0)
		{
			if (ptr == head)
				head = ptr->next;
			previous->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			previous = ptr;
		}
		else
		{
			previous = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}
