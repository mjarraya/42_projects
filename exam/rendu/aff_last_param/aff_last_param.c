/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:11:29 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/07 16:14:08 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		write(1, "\n", 1);
	if (argc >= 2)
	{
		while (argv[argc-1][i])
		{
			write(1, &argv[argc-1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
