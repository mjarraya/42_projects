/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:02:50 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/18 12:40:11 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 3000

typedef	struct	s_struct
{
	char		*buf;
	char		*buf2;
}				t_struct;

int				get_next_line(int const fd, char **line);

#endif
