/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:17:58 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:42:40 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_optlst	*opts;
	t_file		*file;
	DIR			*directory;

	file = NULL;
	directory = NULL;
	if (!(opts = (t_optlst*)ft_memalloc(sizeof(t_optlst))))
		return (1);
	if (argc > 1)
	{
		opts = ft_all_parse(argc, argv, opts);
		check_err_file(opts);
		if (opts->ba == 0)
			no_arg(opts, file, directory);
		else if (opts->elem[0])
			print_elem(opts, file, directory, -1);
	}
	else
	{
		opts = (t_optlst*)ft_memalloc(sizeof(t_optlst));
		opts = init_opts(argc, opts);
		no_arg(opts, file, directory);
	}
	return (0);
}
