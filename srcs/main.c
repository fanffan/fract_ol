/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:26:48 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/20 16:17:56 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_isfract2(char *str1, char *str2)
{
	char *cpy;

	cpy = ft_strtolower(str2);
	if (!ft_strcmp(str1, cpy))
	{
		ft_strdel(&cpy);
		return (1);
	}
	ft_strdel(&cpy);
	return (0);
}

int		ft_isfract(char *str)
{
	if (ft_isfract2("julia", str) || ft_isfract2("mandelbrot",
	str) || ft_isfract2("mandelbrot5", str) ||
	ft_isfract2("mandelbrot4", str) || ft_isfract2("burning_ship",
	str) || ft_isfract2("tricorne", str) ||
	ft_isfract2("burning_ship2", str) ||
	ft_isfract2("celtic_heart", str))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1 || ac > 2 || !ft_isfract(av[1]))
		ft_printf("Usage: ./fractol (julia | mandelbrot | mandelbrot4 | \
mandelbrot5 | burning_ship | burning_ship2 | tricorne | celtic_heart)\n");
	else
		ft_launcher(av[1]);
	return (0);
}
