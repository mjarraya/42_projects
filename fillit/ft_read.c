/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:55:30 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/21 13:30:56 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

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

int		ft_checklinelen(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != '\n')
		{
			if (j > 4)
				return (0);
			j++;
			i++;
		}
		i++;
	}
	return (1);
}

char	*ft_split(char *s)
{
	int		i;
	int		j;

	if (!s || ft_checklinelen(s) == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\n' || (s[i] == '\n' && s[i - 1] == '\n'))
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\n';
	s[j + 1] = '\0';
	return (s);
}

int		ft_counttetri(char *s)
{
	int	nb;

	nb = (ft_charcount(s, '#') / 4);
	return (nb);
}



t_block		*ft_letters(char **s)
{
	int		i;
	char	c;
	int		j;
	t_block	*piece;
	t_block	*begin;

	piece = malloc(sizeof(t_block));
	begin = piece;
	piece->idx = 0;
	i = 0;
	c = 'A';
	while (s[i])
	{
		j = 0;
		piece->tetri = malloc(sizeof(char) * 17);
		while (s[i][j] != '\0')
		{
			if (s[i][j] == '#')
				piece->tetri[j] = c;
			else
				piece->tetri[j] = '.';
			j++;
		}
		piece->tetri[j] = '\0';
		piece->next = malloc(sizeof(t_block));
		piece->idx += i;
		printf("%s%d\n", piece->tetri, piece->idx);
		i++;
		c++;
		piece = piece->next;
	}
	return (begin);
}

int		main(int argc, char **argv)
{
	char	**split;
	int		i;

	split = ft_strsplit(ft_split(ft_read(argv[1])), '\n');
	i = 0;
	while (split[i])
	{
		ft_shift(split[i]);
		i++;
	}
	ft_letters(split);
	return (0);
}