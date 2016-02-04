/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:10:39 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/03 18:46:07 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * - 1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *nbr)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 0;
	while ((nbr[i] == '-' || nbr[i] == '+') && nbr[i] != '\0')
	{
		if (nbr[i] == '-')
			neg++;
		i++;
	}
	while (nbr[i] != '\0')
	{
		res = (res * 10) + (nbr[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		return (-res);
	return (res);
}

int		prime(int n)
{
	int	i;

	i = n - 1;
	while (i > 1)
	{
		if (n % i == 0)
			return (0);
		i--;
	}
	return (1);
}

void	add_prime_sum(char *str)
{
	int	i;
	int j;

	i = ft_atoi(str);
	if (i < 2)
	{
		ft_putnbr(0);
		return ;
	}
	while (i > 1)
	{
		if (prime(i) == 1)
			j = j + i;
		i--;
	}
	ft_putnbr(j);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		add_prime_sum(argv[1]);
	if (argc != 2)
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
