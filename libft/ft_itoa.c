/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:56:09 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/11 15:30:58 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int i)
{
	int	k;

	k = 0;
	while (i > 0)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

static char		*ft_checkvalue(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

char			*ft_itoa(int n)
{
	unsigned int	i;
	int				len;
	char			*s;

	len = 0;
	if (!(s = malloc(sizeof(char) * (11))))
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (ft_checkvalue(n));
	if (n < 0)
	{
		s[0] = '-';
		len++;
		n = n * -1;
	}
	i = n;
	len = len + ft_count(i);
	s[len + 1] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
