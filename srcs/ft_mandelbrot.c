/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:26:37 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 17:49:56 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot(t_env *env, double *zr_zi, double *cr_ci)
{
	double	tmp;
	int		i;

	i = 0;
	while (1)
	{
		tmp = zr_zi[0];
		zr_zi[0] = zr_zi[0] * zr_zi[0] - zr_zi[1] * zr_zi[1] + cr_ci[0];
		zr_zi[1] = 2 * zr_zi[1] * tmp + cr_ci[1];
		i++;
		if (zr_zi[0] * zr_zi[0] + zr_zi[1] * zr_zi[1] >= 5 || i >= env->it)
			break ;
	}
	return (i);
}
