/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:29:52 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/01 19:50:02 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		div_ten(int nb)
{
	int		i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_itoa(int nb)
{
	char	*tab;
	int		i;
	int		nb_cool;

	nb_cool = div_ten(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if(!(tab = (char *)malloc(sizeof(char) * nb_cool + 2)))
		return (NULL);
	tab[nb_cool] = '\0';
	if (nb == 0)
	{
		tab[0] = '0';
		return (tab);
	}
	i = 0;
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
	//	i++;
	}
	i = nb_cool;	
	while (nb > 0)
	{
		i--;
		tab[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (tab);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(atoi(argv[1])));
	return (0);
}
