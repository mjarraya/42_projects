/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:20:28 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/22 18:40:02 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char c)
{
	 if (c >= 33 && c <= 126)
		 return (1);
	 return (0);
}

void	last_word(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0)
	{
		i--;
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		while (is_printable(str[i]) == 1)
			i--;
		i++;
		while (str[i] && str[i] != '\t' && str[i] != ' ')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
}
