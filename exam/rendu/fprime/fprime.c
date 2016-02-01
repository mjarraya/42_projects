/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:39:37 by exam              #+#    #+#             */
/*   Updated: 2016/01/26 12:23:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int nb)
{
	int		i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fprime(int nb)
{
	int		i;

	if (is_prime(nb) == 1 || nb == 1)
	{
		printf("%d\n", nb);
		return ;
	}
	i = 2;
	while (i <= nb)
	{
		if (is_prime(i) == 1 && nb % i == 0)
		{
			printf("%d", i);
			nb = nb / i;
			while (i <= nb)
			{
				if (is_prime(i) == 1)
				{
					printf("*");
					break;
				}
				i++;
			}
		}
		else
			i++;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	fprime(atoi(argv[1]));
	return (0);
}
