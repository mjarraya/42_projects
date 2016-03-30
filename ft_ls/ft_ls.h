/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:07:45 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/30 15:55:27 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <sys/stat.h>

typedef struct		s_optlst
{
	int				flaga;
	int				flagl;
	int				flagr;
	int				flagt;
	int				flagur;
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
