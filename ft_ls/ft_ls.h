/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:07:45 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/29 23:21:29 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <sys/stat.h>

typedef struct		s_optlst
{
	int				flag;
}					t_optlst;

typedef struct		s_files
{
	struct stat		*stat;
	char			*name;
	char			*dir;
	struct s_files	*next;
}					t_files;

enum
{
	ARG,
	FICH
};

#endif
