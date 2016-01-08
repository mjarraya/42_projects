/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:02:56 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/08 19:10:59 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

#include <stdio.h>

static char	*ft_fill_line(char *buf, char *line)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (line)
		i += ft_strlen(line);
	tmp = line;
	line = (char *)ft_memalloc(i + 1);
	i = 0;
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0' && buf[j] != '\n')
	{	
		line[i] = buf[j];
		i++;
		j++;
	}
	line[i] = '\0';
	free(tmp);
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static t_struct *gnl = NULL;
	
	if (!gnl)
	{
		gnl = (t_struct *)ft_memalloc(sizeof(t_struct));
		gnl->buf = (char *)ft_memalloc(BUFF_SIZE + 1);
		gnl->buf2 = NULL;
	}
	ret = 1;
	*line = (char *)ft_memalloc(1);
	while (ret && (!(gnl->buf2 = ft_strchr(gnl->buf, '\n'))))
	{
		ret = read(fd, gnl->buf, BUFF_SIZE);
		if (ft_strchr(gnl->buf, '\n') == NULL)
			*line = ft_fill_line(gnl->buf, *line);	
		else
		{
			*line = ft_fill_line(gnl->buf, *line);
			return (1);
		}
	}
	return (0);
}

#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);	
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
