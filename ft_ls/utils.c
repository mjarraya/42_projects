/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:18:32 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/27 21:04:46 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_illegal_options(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ls [-Ralrt] [file ...]", 2);
}

char	ft_is_option(char c)
{
	if (c == 'R' || c == 'l' || c == 'a' || c == 'r' || c == 't')
		return (1);
	return (0);
}
