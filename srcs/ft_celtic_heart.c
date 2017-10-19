/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_celtic_heart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 17:48:00 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_celtic_heart(t_env *env, double *zr_zi, double *cr_ci)
{
	double	tmp;
	int		i;

	i = 0;
	while (1)
	{
		tmp = zr_zi[0];
		zr_zi[0] = fabs(zr_zi[0] * zr_zi[0] - zr_zi[1] * zr_zi[1]) + cr_ci[0];
		zr_zi[1] = fabs(tmp) * zr_zi[1] * 2 + cr_ci[1];
		i++;
		if (zr_zi[0] * zr_zi[0] + zr_zi[1] * zr_zi[1] >= 5 || i >= env->it)
			break ;
	}
	return (i);
}
