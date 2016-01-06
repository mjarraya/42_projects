/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:31:56 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/06 13:45:02 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validform(char *split, int i, int j)
{
	int	touch;

	i = 0;
	while (split[i] != '\0')
	{
		touch = 0;
		j = 1;
		while (split[i] != '\n' && split[i] != '\0')
		{
			if (split[i] == '#' && split[i] == split[i + 1] && j % 4 != 0)
				touch++;
			if (split[i] == '#' && split[i] == split[i - 1] && j % 4 != 1)
				touch++;
			if (split[i] == '#' && split[i] == split[i + 4] && j < 13)
				touch++;
			if (split[i] == '#' && split[i] == split[i - 4] && j > 4)
				touch++;
			j++;
			i++;
		}
		if (touch < 6)
			return (0);
		i++;
	}
	return (1);
}

int		ft_validpattern(char *split)
{
	int	i;
	int	point;
	int	hash;
	int	j;

	i = 0;
	while (split[i] != '\0')
	{
		hash = 0;
		point = 0;
		j = 0;
		while (split[i] != '\n' && split[i] != '\0')
		{
			if (split[i] == '.')
				point++;
			else if (split[i] == '#')
				hash++;
			i++;
			j++;
		}
		if (j != 16 || point != 12 || hash != 4)
			return (0);
		i++;
	}
	return (1);
}

int		ft_validmap(char *split)
{
	if (ft_charcount(split, '#') > 104)
		return (0);
	if (ft_strlen(split) < 16)
		return (0);
	if (!split)
		return (0);
	if ((ft_validpattern(split) == 0) || (ft_validform(split, 0, 0) == 0))
		return (0);
	return (1);
}

char	*ft_read(char *s)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(s, O_RDONLY);
	buf = malloc(sizeof(char *) * (BUF_SIZE));
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (buf);
}
