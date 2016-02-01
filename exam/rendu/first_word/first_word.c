/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:40:09 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/14 18:38:37 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

void	first_word(char *str)
{
	int		i;

	i = 0;
	while (is_space(str[i]) == 1 && str[i] != '\0')
		i++;
	while (is_space(str[i]) == 0 && str[i] != '\0')
	{
		write(1, &str[i], 1);
			i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
