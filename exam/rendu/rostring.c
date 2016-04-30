/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:30:18 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/08 19:06:37 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_space(char c)
{
		if (c == ' ' || c == '\t')
				return (1);
		return (0);
}

int		count_words(char *str)
{
		int		i;
		int		nb;

		nb = 0;
		i = 0;
		while (is_space(str[i]) && str[i])
				i++;
		while (str[i])
		{
				if (is_space(str[i]) == 0)
				{
						nb++;
						while (is_space(str[i]) == 0 && str[i])
								i++;
				}
				else
						i++;
		}
		return (nb);
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
								write(1, &str[i], 1);
				}
				i++;
		}
		if (count_words(str) > 1)
				write(1, " ", 1);
		i = 0;
		while (str[i] && is_space(str[i]))
				i++;
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
		return (0);
}
