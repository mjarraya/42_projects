/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:53:19 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/02 18:00:10 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     main(int ac, char **av)
{
	int     fd;
	char    *line;
	int		i;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((i = get_next_line((int const)fd, &line)) > 0)
		printf("%d %s\n", i, line);
	printf("%d\n", get_next_line(fd, &line));
	return (1);
}
