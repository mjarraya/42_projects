/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 19:10:51 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 21:36:16 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_minimize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	to_upper(char c)
{
	char	u;

	if (c >= 'a' && c <= 'z')
		u = c - 32;
	else
		u = c;
	write(1, &u, 1);
}

int		ft_isdigitalpha(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
		return (0);
}

void	str_capitalizer(char *str)
{
	int		i;

	ft_minimize(str);
	i = 0;
	while (str[i])
	{
		if (ft_isdigitalpha(str[i]) == 1 && (ft_isdigitalpha(str[i - 1]) == 0))
			to_upper(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		str_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	if (argc == 1)
		write(1, "\n", 1);
	return (0);
}
