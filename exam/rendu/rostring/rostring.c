/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:41:32 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/23 16:18:58 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (is_space(str[i]) == 0 && (is_space(str[i + 1]) == 1 || str[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

void	rostring(char *str)
{
	int		i;

	i = 0;
	while (str[i] && is_space(str[i]) == 1)
		i++;
	while (str[i] && is_space(str[i]) == 0)
		i++;
	while (str[i] && is_space(str[i]) == 1)
		i++;
	while (str[i])
	{
		if (is_space(str[i]) == 0)
			write(1, &str[i], 1);
		else
		{
			if (is_space(str[i + 1]) == 0 && str[i + 1] != '\0')
				write(1, " ", 1);
		}
		i++;
	}
	i = 0;
	while (str[i] && is_space(str[i]) == 1)
		i++;
	if (count_words(str) > 1)
		write(1, " ", 1);
	while (str[i] && is_space(str[i]) == 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rostring(argv[1]);
}
