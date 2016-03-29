/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:40:57 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/24 17:33:16 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_err(int e)
{
	if (e == 0 || e == 1)
	{
		ft_putstr_fd("Usage: ./fractol [fractal ", 2);
		ft_putstr_fd("(mandelbrot/julia/burningship)", 2);
		ft_putstr_fd("] [--optional color ", 2);
		ft_putstr_fd("(red/orange/blue/bw/random)", 2);
		ft_putendl_fd("]", 2);
	}
	exit(1);
}

int		ft_fractol_verif(char *name)
{
	if (!ft_strcmp_case(name, "mandelbrot"))
		return (1);
	if (!ft_strcmp_case(name, "julia"))
		return (2);
	if (!ft_strcmp_case(name, "burningship"))
		return (3);
	else
		return (0);
}

int		ft_fractol_verif_col(char *color)
{
	if (!ft_strcmp_case(color, "red"))
		return (1);
	if (!ft_strcmp_case(color, "blue"))
		return (1);
	if (!ft_strcmp_case(color, "bw"))
		return (1);
	if (!ft_strcmp_case(color, "orange"))
		return (1);
	if (!ft_strcmp_case(color, "random"))
		return (1);
	else
		return (0);
}
