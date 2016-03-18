/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:49:37 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/12 12:04:14 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)());
void	ft_list_clear(t_list **begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_push_params(int ac, char **av);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_create_elem(void *data);
//t_list	*ft_list_reverse(t_list *begin_list);
t_list	*ft_list_reverse(t_list *begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
//void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_insert(t_list **begin_list, t_list *list);
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
t_list	*ft_sort_ascii(t_list *begin_list, int (*cmp)());

void	ft_printlist(t_list *lst)
{
	while (lst)
	{
		printf("data: %d\n", (int)lst->data);
		//printf("data: %s\n", (char *)lst->data);
		lst = lst->next;
	}
}

t_list	*lst_new(void *data)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->next = 0;
	lst->data = data;
	return (lst);
}

int		cmp(void *a, void *b)
{
	if ((int)a == (int)b)
		return (0);
	else
		return ((int)a - (int)b);
}

int		main(int ac, char **av)
{
	t_list		*lst;
	t_list		*lst2;

	lst = lst_new((void*)1);
	lst2 = lst_new((void*)14);
	lst->next = lst_new((void*)3);
//	lst2->next = lst_new((void*)4);
	lst->next->next = lst_new((void*)5);
//	lst2->next->next = lst_new((void*)6);
	lst->next->next->next = lst_new((void*)9);
//	lst2->next->next->next = lst_new((void*)8);
	lst->next->next->next->next = lst_new((void*)10);
	lst->next->next->next->next->next = lst_new((void*)11);
	lst->next->next->next->next->next->next = lst_new((void*)12);
	lst->next->next->next->next->next->next->next = lst_new((void*)15);
	ft_printlist(lst);
//	ft_printlist(lst2);
	//ft_list_remove_if(&lst, (void*)5, &cmp);
	//ft_list_push_back(&lst, (void*)1);
	//ft_list_push_front(&lst, (void*)1);
	//ft_list_size(lst);
	//ft_printlist(ft_list_last(lst));
	//lst = ft_list_push_params(ac, av);
//	ft_list_clear(&lst);
	//ft_printlist_list_at(lst, 5);
	//lst = ft_list_find(lst, (void*)1, &cmp);
	//ft_list_merge(&lst, lst2);
	//ft_list_sort(&lst, &cmp);
	//ft_sorted_list_insert(&lst, (void *)1, &cmp);
	ft_sorted_list_insert(&lst, lst2);
//	ft_sorted_list_merge(&lst, lst2, &cmp);
	printf("---------------------------------------\n");
	//lst2 = ft_sort_ascii(lst, &cmp);
	printf("FT_REVERSE_LIST: \n");
	ft_printlist(lst);
	return (0);
}
