/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:06:45 by exam              #+#    #+#             */
/*   Updated: 2016/01/26 11:38:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		pgcd(int a, int b)
{
	int		res;
	int		p;

	if (a < b)
		p = b;
	else
		p = a;
	res = 1;
	while (p > res)
	{
		if (a % p == 0 && b % p == 0)
			res = p;
		p--;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	printf("%d\n", pgcd(atoi(argv[1]), atoi(argv[2])));
}
