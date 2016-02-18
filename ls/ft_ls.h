/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:43:49 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 06:54:34 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct		s_files
{
	char			type;
	char			*perms;
	int				links;
	char			*owner;
	char			*group;
	int				size;
	/*char			*time_acc;
	char			*time_mod;
	char			*time_sta;*/
	dev_t			device;
	char			*name;
	char			*parent;
	struct s_files	*next;

}					t_files;

typedef struct		s_args
{
	char			**elem;
	int				cap_r;
	int				l;
	int				a;
	int				r;
	int				t;
}					t_args;

t_files				*ft_fill_s_files(char *filename);
int					read_directory(t_files *current_dir, t_args *args,
	t_files **head);
void	ft_illegal_options(char c);
char	ft_is_option(char c);
t_args	ft_parse(int argc, char **argv);

#endif
