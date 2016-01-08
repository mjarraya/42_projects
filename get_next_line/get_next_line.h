/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:02:50 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/08 19:12:04 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 1 
# define DEBUG printf("%d - %s - %s\n", __LINE__, __FILE__, __func__);
typedef	struct	s_struct
{
	char		*buf;
	char		*buf2;
}				t_struct;

int	get_next_line(int const fd, char **line);

#endif
