/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:12:23 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/01 19:19:20 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]) == 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	rev_wstr(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		i--;
		while (is_space(str[i]) == 0 && i >= 0)
			i--;
		i++;
		put_word(&str[i]);
		if (i > 0)
			write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rev_wstr(argv[1]);
	return (0);
}
