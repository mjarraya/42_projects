/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 00:21:19 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:03:57 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cnumber(int n)
{
	int			count;

	count = n == 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_arginv(t_optlst *opts)
{
	int i;

	i = 0;
	while (i < ft_tablen(opts->invalid))
	{
		ft_no_directory(opts->invalid[i]);
		i++;
	}
}

void	print_invalid(t_optlst *opts)
{
	opts->invalid = ft_sorted_tab(opts->invalid);
	ft_arginv(opts);
}
