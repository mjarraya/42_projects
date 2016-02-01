/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:41:39 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/22 18:50:25 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
