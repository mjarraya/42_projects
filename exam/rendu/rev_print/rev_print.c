/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:39:27 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/13 14:47:38 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_print(char *str)
{
	char	*str_cpy;
	int		i;
	int		j;

	str_cpy = str;
	i = 0;
	j = 0;
	while (str[i])
		i++;
	i = i - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	rev_print(av[1]);
	return (0);
}
