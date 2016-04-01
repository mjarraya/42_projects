/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:34:36 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:42:42 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_optlst	*arg_n(t_optlst *opts)
{
	opts->elem[opts->cd] = NULL;
	opts->files[opts->cf] = NULL;
	opts->invalid[opts->ce] = NULL;
	return (opts);
}

int			ft_dircheck(char *argv, int j, t_optlst *opts, char type)
{
	if (!ft_is_dir(argv) || type == 'd')
	{
		opts->elem[j] = ft_strdup(argv);
		return (1);
	}
	return (0);
}

int			ft_filecheck(char *argv, int f, t_optlst *opts)
{
	if (ft_is_file(argv) == 1)
	{
		opts->files[f] = ft_strdup(argv);
		return (1);
	}
	return (0);
}

t_optlst	*sort_args(char **argv, t_optlst *opts)
{
	t_stat	fstat;
	char	type;

	type = 0;
	while (argv[opts->ba] != NULL)
	{
		lstat(argv[opts->ba], &fstat);
		type = ft_gettype(fstat);
		if (type == 'l' && opts->l == 1 && lstat(argv[opts->ba], &fstat) != -1)
			ft_link(argv, opts);
		else if (ft_dircheck(argv[opts->ba], opts->cd, opts, type) == 1 &&
				lstat(argv[opts->ba], &fstat) != -1)
			opts->cd++;
		else if (ft_filecheck(argv[opts->ba], opts->cf, opts) == 1)
			opts->cf++;
		else
		{
			opts->invalid[opts->ce] = ft_strdup(argv[opts->ba]);
			opts->ce++;
		}
		opts->ba++;
	}
	opts = arg_n(opts);
	return (opts);
}
