/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:44:50 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/14 15:54:21 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		wdmatch(char *s1, char *s2)
{
	int		i;
	int		count;
	int		len;
	
	i = 0;
	while (s1[i])
		i++;
	len = i;
	i = 0;
	count = 0;
	while (s2[i])
	{
		if (s2[i] == s1[count])
			count++;
		i++;
	}
	if (count == len)
		return (1);
	return (0);
}

void	ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (wdmatch(argv[1], argv[2]) == 1)
		ft_putendl(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
