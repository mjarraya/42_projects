/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:45:04 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/03 17:55:38 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_illegal_options(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-Ralrt] [file...]\n");
}

void	ft_invalid_argument(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}

int		ft_isoption(char c)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
		return (1);
	return (0);
}

void	ft_parse_options(int argc, char **argv)
{
	int		i;
	size_t	j;
	char	tab[256];

	i = 1;
	if (argc == 1)
		ft_list_files(argc, argv);
	while (i < argc)
	{	
		if (argv[i][0] != '-' || argv[i][1] == '-')
		{
			if (argv[i][1] == '-')
				ft_illegal_options(argv[i][j]);
			if (argv[i][1] == '\0')
				ft_putendl("ls: -: No such file or directory");
			return ;
		}
		j = 1;
		while (argv[i][j])
		{
			tab[(size_t)(unsigned char)argv[i][j]] = 1;
			if (ft_isoption(argv[i][j]) == 0)
			{
				ft_illegal_options(argv[i][j]);
				return ;
			}
			j++;
		}
		i++;
		if (tab[(size_t)(unsigned char)'l'] == 1)
				ft_ls_l(argc, argv);
	}
}
