/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:15:16 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/18 10:23:10 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_env *env, int x, int xmax)
{
	double		tmp;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		zoom_x;
	double		zoom_y;
	int		i;
	int		y;

	zoom_x = HEIGHT / (env->x2 - env->x1) + env->xmouse;
	zoom_y = WIDTH / (env->y2 - env->y1) + env->ymouse;
	while (x < xmax && x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH) 
		{
			i = 0;
			c_r = 0.285 + env->xmouse;
			c_i = 0.01 + env->ymouse;
			z_r = x / zoom_x + env->x1;
			z_i = y / zoom_y + env->y1;
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
				env->data[y * WIDTH + x] = 0;
			else
				env->data[y * WIDTH + x] = 0x0000FF * i / env->it;
			y++;
		}
		x++;
	}
}
