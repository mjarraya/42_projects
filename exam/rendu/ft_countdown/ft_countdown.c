/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 14:38:14 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/23 14:39:10 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(void)
{
	char	n;

	n = '9';
	while (n >= '0')
	{
		write(1, &n, 1);
		n--;
	}
	write(1, "\n", 1);
	return (0);
}
