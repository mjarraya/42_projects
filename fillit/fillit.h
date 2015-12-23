/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:44:07 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/21 13:33:53 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUF_SIZE 1024

typedef	struct	s_hash
{
	int a;
	int b;
	int	c;
	int d;
}				t_hash;

char	*ft_read(char *s);
char	*ft_split(char *s);
int		ft_validmap(char *split);
int		ft_validform(char *split, int i, int j);
char	*ft_shift_left(char *s);
char	*ft_shift_right(char *s);
char	*ft_shift(char *s);
int		ft_counttetri(char *s);

#endif
