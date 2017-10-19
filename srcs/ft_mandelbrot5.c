/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 17:54:51 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot5(t_env *env, double *zr_zi, double *cr_ci)
{
	double	tmp;
	double	z_rt;
	double	z_it;
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (1)
	{
		tmp = zr_zi[0];
		z_rt = zr_zi[0] * zr_zi[0];
		z_it = zr_zi[1] * zr_zi[1];
		zr_zi[0] = -(z_rt - (z_it * 3.0)) * zr_zi[0] + cr_ci[0];
		zr_zi[1] = ((z_rt * 3.0) - z_it) * zr_zi[1] + cr_ci[1];
		i++;
		if (zr_zi[0] * zr_zi[0] + zr_zi[1] * zr_zi[1] >= 5 || i >= env->it)
			break ;
	}
	return (i);
}
