/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:47:51 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/11 14:11:27 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	is_first(char c, char *str, int pos)
{
	int		i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (pos == i)
		write(1, &c, 1);
}

void	print_union(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	i = 0;
	while (s1[i] != '\0')
	{
		is_first(s1[i], s1, i);
		i++;
	}
}
		
int		main(int argc, char **argv)
{
	if (argc == 3)
		print_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
