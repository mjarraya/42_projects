/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:43:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/14 19:03:10 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

void	epur_str(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && is_space(str[i]) == 1)
		i++;
	while (str[j])
		j++;
	while (is_space(str[j]) == 1)
		j--;
	while (str[i] && i <= j)
	{
		if(is_space(str[i]) == 0 || (is_space(str[i]) == 1 &&
					is_space(str[i - 1]) == 0))
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	epur_str(argv[1]);
	return (0);
}
