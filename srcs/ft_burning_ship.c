/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 17:47:30 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_burning_ship(t_env *env, double *zr_zi, double *cr_ci)
{
	double	tmp;
	double	z_rt;
	double	z_it;
	int		i;

	i = 0;
	while (1)
	{
		tmp = zr_zi[0];
		z_rt = zr_zi[0] * zr_zi[0];
		z_it = zr_zi[1] * zr_zi[1];
		zr_zi[0] = fabs(zr_zi[0]) * ((z_rt * z_rt) - 10 * (z_rt * z_it) +
				5 * (z_it * z_it)) + cr_ci[0];
		zr_zi[1] = fabs(zr_zi[1]) * (5 * (z_rt * z_rt) - 10 * (z_rt * z_it)
				+ (z_it * z_it)) + cr_ci[1];
		i++;
		if (zr_zi[0] * zr_zi[0] + zr_zi[1] * zr_zi[1] >= 5 || i >= env->it)
			break ;
	}
	return (i);
}
