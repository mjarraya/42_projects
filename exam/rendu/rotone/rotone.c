/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:05:31 by exam              #+#    #+#             */
/*   Updated: 2016/01/26 10:28:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	rotone(char c)
{
	if (c >= 'a' && c < 'z')
		return (c = c + 1);
	if (c >= 'A' && c < 'Z')
		return (c = c + 1);
	if (c == 'z' || c == 'Z')
		return (c = c - 25);
	return (c);
}

void	rot(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = rotone(str[i]);
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}


int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rot(argv[1]);	
	return (0);
}
