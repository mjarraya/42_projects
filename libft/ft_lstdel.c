/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:01:55 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/01 18:48:14 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cnt;

	while (*alst)
	{
		cnt = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = cnt;
	}
}
