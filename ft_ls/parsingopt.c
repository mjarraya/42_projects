/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:36:48 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 15:57:40 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_optlst	*init_opts(int argc, t_optlst *opts)
{
	if (!(opts->elem = ft_memalloc(sizeof(char *) * argc + 1)))
		return (opts);
	if (!(opts->files = ft_memalloc(sizeof(char *) * argc + 1)))
		return (opts);
	if (!(opts->invalid = ft_memalloc(sizeof(char *) * argc + 1)))
		return (opts);
	opts->ur = 0;
	opts->l = 0;
	opts->a = 0;
	opts->r = 0;
	opts->t = 0;
	opts->tot = 0;
	opts->ct = 1;
	opts->ba = 0;
	opts->cd = 0;
	opts->cf = 0;
	opts->ce = 0;
	opts->g = 0;
	return (opts);
}

void		check_azero(char *argv, int end_opt, t_optlst *opts)
{
	if (argv[0] == '-' && argv[1] == '-' && !argv[2])
		return ;
	if (argv[0] == '-' && !argv[1])
	{
		ft_no_directory("-");
		exit(1);
	}
	if (argv[0] == '-' && end_opt == 0)
	{
		end_opt = (argv[1] == '\0' ? 1 : (0));
		if (ft_checkfor_opt(argv, opts) == 0)
			exit(1);
	}
	return ;
}

t_optlst	*ft_end_opt(t_optlst *o, char **av)
{
	if (av[o->ct][0] == '-' && av[o->ct][1] == '-' && !av[o->ct + 1])
		o->ba = 0;
	else if (av[o->ct][0] == '-' && av[o->ct][1] == '-' && av[o->ct + 1])
		o->ba++;
	return (o);
}

t_optlst	*check_opts(char **av, t_optlst *o)
{
	int end_opt;

	end_opt = 0;
	while (av[o->ct])
	{
		if (av[o->ct][0] == '\0')
		{
			ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
			exit(1);
		}
		check_azero(av[o->ct], end_opt, o);
		if ((av[o->ct][0] != '-' && end_opt != 1) ||
		(!ft_strcmp(av[o->ct], "--")))
		{
			o->ba = o->ct;
			end_opt = 1;
			o = ft_end_opt(o, av);
			break ;
		}
		o->ct++;
	}
	return (o);
}

t_optlst	*ft_all_parse(int argc, char **argv, t_optlst *opts)
{
	opts = init_opts(argc, opts);
	opts = check_opts(argv, opts);
	if (opts->ba != 0)
		opts = sort_args(argv, opts);
	return (opts);
}
