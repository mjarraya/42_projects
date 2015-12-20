/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:50:02 by mjarraya          #+#    #+#             */
/*   Updated: 2015/12/20 18:20:10 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*ft_shift_left(char *s)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = s[i];
	while (s[i + 1] != '\0')
	{
		s[i] = s[i + 1];
		i++;
	}
	s[i] = tmp;
	return (s);
}

char	*ft_shift_right(char *s)
{
	int		i;
	char	tmp;

	i = ft_strlen(s) - 1;
	tmp = s[i];
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[i] = tmp;
	return (s);
}



char	*ft_shift(char *s)
{
	while (s[0] != '#')
		ft_shift_left(s);
	while (ft_validform(s) != 1)
		ft_shift_right(s);
	return (s);
}
