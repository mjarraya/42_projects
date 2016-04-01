/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingopt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:57:57 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:42:46 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fill_opt(char c, t_optlst *opts)
{
	if (c == 'R')
		opts->ur = 1;
	else if (c == 'l')
		opts->l = 1;
	else if (c == 'a')
		opts->a = 1;
	else if (c == 'r')
		opts->r = 1;
	else if (c == 't')
		opts->t = 1;
	else if (c == 'G')
		opts->g = 1;
}

void	ft_illegal_options(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ls [-RalrtG] [file ...]", 2);
}

char	ft_is_option(char c)
{
	if (c == 'R' || c == 'l' || c == 'a' || c == 'r' || c == 't' || c == 'G')
		return (1);
	return (0);
}

int		ft_checkfor_opt(char *arg, t_optlst *opts)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (ft_is_option(arg[i]) == 0)
		{
			ft_illegal_options(arg[i]);
			return (0);
		}
		ft_fill_opt(arg[i], opts);
		i++;
	}
	return (1);
}
