/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:02:56 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/18 12:38:52 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

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
	ft_strcpy(line, tmp);
	i = ft_strlen(tmp);
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

static void	init_buf(t_struct **gnl, char **line)
{
	*line = (char *)ft_memalloc(1);
	if (!*gnl)
	{
		*gnl = (t_struct *)ft_memalloc(sizeof(t_struct));
		(*gnl)->buf = (char *)ft_memalloc(BUFF_SIZE + 1);
		(*gnl)->buf2 = NULL;
	}
}

static int	ft_get_next_line(int const fd, char **line)
{
	int				ret;
	static t_struct *gnl = NULL;

	init_buf(&gnl, line);
	while (gnl->buf2 || (ret = read(fd, gnl->buf, BUFF_SIZE)))
	{
		if (gnl->buf2)
		{
			*line = ft_fill_line(gnl->buf2 + 1, *line);
			if ((gnl->buf2 = ft_strchr(gnl->buf2 + 1, '\n')) == NULL)
			{
				if ((ret = read(fd, gnl->buf, BUFF_SIZE)) == 0)
					return (0);
			}
			else
				return (1);
		}
		if (ret == -1)
			return (-1);
		gnl->buf[ret] = '\0';
		*line = ft_fill_line(gnl->buf, *line);
		if ((gnl->buf2 = ft_strchr(gnl->buf, '\n')) != NULL)
			return (1);
	}
	return ((ret || **line) ? 1 : 0);
}

int			get_next_line(int const fd, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	return (ft_get_next_line(fd, line));
}
