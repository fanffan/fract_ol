/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 13:33:53 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot4_2(t_env *env, int x, double zoom_x, double zoom_y)
{
	double	c_r;
	double 	c_i;
	double 	z_r;
	double 	z_rt;
	double 	z_i;
	double 	z_it;
	double 	tmp;
	int 	i;
	int 	y;

	y = 0;
	while (y < HEIGHT)
	{

		z_r = 4 * env->xmouse;
		z_i = 4 * env->ymouse;
		i = 0;
		c_i = y / zoom_y + env->y1;
		c_r = x / zoom_x + env->x1;
		while (1)
		{
			tmp = z_r;
			z_rt = z_r * z_r;
			z_it = z_i * z_i;
			z_r = z_rt * z_rt + z_it * z_it - 6 * z_rt * z_it + c_r;
			z_i = 4 * tmp * z_i * (z_rt - z_it) + c_i;
			i++;
			if (z_r * z_r + z_i*z_i >= 5 || i >= env->it)
				break;
		}
		if (i == env->it)
			env->data[y * WIDTH + x] = 0;
		else
			env->data[y * WIDTH + x] = env->color * i / (int)env->it & env->color;
		y++;
	}
}

void	ft_mandelbrot4(t_env *env, int x, int xmax)
{
	double 	zoom_x;
	double 	zoom_y;

	zoom_x = HEIGHT /(env->x2 - env->x1);
	zoom_y = WIDTH /(env->y2 - env->y1);
	while (x < xmax && x < WIDTH)
	{
		ft_mandelbrot4_2(env, x, zoom_x, zoom_y);
		x++;
	}
}
