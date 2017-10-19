/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:26:48 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 14:09:38 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_isfract(char *str)
{
	if (!ft_strcmp("julia", ft_strtolower(str)) || !ft_strcmp("mandelbrot",
	ft_strtolower(str)) || !ft_strcmp("mandelbrot5", ft_strtolower(str)) ||
	!ft_strcmp("mandelbrot4", ft_strtolower(str)) || !ft_strcmp("burning_ship",
	ft_strtolower(str)) || !ft_strcmp("tricorne", ft_strtolower(str)) ||
	!ft_strcmp("burning_ship2", ft_strtolower(str)) ||
	!ft_strcmp("celtic_heart", ft_strtolower(str)))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1 || ac > 2 || !ft_isfract(av[1]))
		ft_printf("Usage: ./fractol (julia | mandelbrot | mandelbrot4 |\
mandelbrot5 | burning_ship | burning_ship2 | tricorne | celtic_heart)\n");
	else
		ft_launcher(av[1]);
	return (0);
}
