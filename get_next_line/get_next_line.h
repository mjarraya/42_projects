/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:02:50 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/09 19:00:21 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 49
# define DEBUG ft_putnbr(__LINE__); ft_putchar(' '); ft_putstr(__FILE__); ft_putchar(' '); ft_putendl(__func__);
# define DEBUG_VAR(x) ft_putstr(x);

typedef	struct	s_struct
{
	char		*buf;
	char		*buf2;
}				t_struct;

int	get_next_line(int const fd, char **line);

#endif
