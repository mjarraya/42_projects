/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:59:27 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/02 16:53:30 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int		ft_strstrcmp(char **tab, char *str)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], str))
			return (1);
		i++;
	}
	return (0);
}

void	inthandler(int sig)
{
	sig = 0;
	ft_putendl_fd("\nminishell quit", 2);
	exit(0);
}

char	**ft_init_tab(void)
{
	char	**tab;

	tab = ft_memalloc(sizeof(char *) * 5);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup("setenv");
	tab[2] = ft_strdup("unsetenv");
	tab[3] = ft_strdup("env");
	tab[4] = NULL;
	return (tab);
}

int		main(int argc, char **argv)
{
	char	**tab;
	char	*line;
	int		i;

	(void)argv;
	tab = ft_init_tab();
	i = 1;
	if (argc != 1)
		return (0);
	signal(SIGINT, inthandler);
	ft_putstr("$> ");
	while(1)
	{
		while (get_next_line(1, &line) > 0)
		{
			ft_putstr("$> ");
			if (!ft_strcmp(line, "exit"))
			{
				ft_putendl_fd("minishell quit", 2);
				exit(0);
			}
			if (!ft_strstrcmp(tab, line))
				ft_putendl_fd("command not found", 2);
			i++;
		}
	}
	return (0);
}
