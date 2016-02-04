/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 14:44:45 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/23 15:10:06 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int	reversed;
	int	i;
	int	bit;

	reversed = octet & 1;
	i = 1;
	while (i < 8)
	{
		bit = octet >> i & 1;
		reversed = reversed << 1;
		reversed = reversed | bit;
		i++;
	}
	return (reversed);
}
