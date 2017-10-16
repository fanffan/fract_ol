/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:15:16 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/16 11:20:50 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_env *env, int x, int xmax)
{
	double	image_x;
	double	image_y;
	double	tmp;
	double c_r;
	double c_i;
	double	z_r;
	double	z_i;
	int i;
	int		y;
	int		zoom;

	zoom = 400;
	image_x = (env->x2 - env->x1) * zoom;
	image_y = (env->y2 - env->y1) * zoom;
	while (x < xmax && x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			i = 0;
			c_r = 0.285;
			c_i = 0.01;
			z_r = x / (zoom + env->x1);
			z_i = y / (zoom + env->y1);
			while (1)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
				if (z_r * z_r + z_i * z_i >= 5 || i >= env->it)
					break;
			}
			if (i == env->it)
				env->data[y * 1000 + x] = 0xFFFFFF;
			else
				env->data[y * 1000 + x] = 0;
			y++;
		}
		x++;
	}
}
