/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:27:10 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/22 15:32:11 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int *tab, unsigned int len)
{
	int		imax;
	
	if (!tab)
		return (0);
	imax = 0;
	while (len > 0)
	{
		len --;
		if (tab[len] > imax)
			imax = tab[len];
	}
	return (imax);
}
