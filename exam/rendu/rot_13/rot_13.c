/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:15:37 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/07 16:22:35 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	wrot_13(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
	{	
		c = c + 13;
		write(1, &c, 1);
		return (0);
	}
	if ((c > 'm' && c <= 'z') || (c > 'M' && c <= 'Z'))
	{
		c = c - 13;
		write(1, &c, 1);
		return (0);
	}
	else
		write(1, &c, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			wrot_13(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

