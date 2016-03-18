/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:57:14 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 22:14:24 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	init_args(int argc)
{
	t_args	args;

	if (!(args.elem = malloc(sizeof(char *) * argc + 1)))
		return (args);
	args.cap_r = 0;
	args.l = 0;
	args.a = 0;
	args.r = 0;
	args.t = 0;
	return (args);
}

void	ft_fill_opt(char c, t_args *args)
{
	if (c == 'R')
		args->cap_r = 1;
	else if (c == 'l')
		args->l = 1;
	else if (c == 'a')
		args->a = 1;
	else if (c == 'r')
		args->r = 1;
	else if (c == 't')
		args->t = 1;
}

int		ft_checkfor_opt(char *arg, t_args *args)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (ft_is_option(arg[i]) == 0)
		{
			ft_illegal_options(arg[i]);
			return (0);
		}
		ft_fill_opt(arg[i], args);
		i++;
	}
	return (1);
}

int		ft_check_args(char **argv, t_args *args, int i, int j, int end_opt)
{
	while (argv[++i])
	{
		if (argv[i][0] == '\0')
		{
			ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
			exit (EXIT_FAILURE);
		}
		if (argv[i][0] == '-' && end_opt == 0)
		{
			end_opt = (argv[i][1] == '\0' ? 1 : (0));
			if (ft_checkfor_opt(argv[i], args) == 0)
				 exit(EXIT_FAILURE);
		}
		if (argv[i][0] != '-')
			end_opt = 1;
		if (end_opt == 1)
		{
			args->elem[j] = ft_strdup(argv[i]);
			j++;
		}
	}
	args->elem[j] = NULL;
	return (1);
}

t_args	ft_parse(int argc, char **argv)
{
	t_args	args;

	args = init_args(argc);
	ft_check_args(argv, &args, 0, 0, 0);
	return (args);
}
