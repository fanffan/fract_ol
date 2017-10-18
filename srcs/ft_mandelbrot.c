/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/18 16:47:42 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot2(t_env *env, int x, double zoom_x, double zoom_y)
{
	double	c_r;
	double 	c_i;
	double 	z_r;
	double 	z_i;
	double 	tmp;
	int 	i;
	int 	y;
	int		col;

	y = 0;
	col = 0;
	while (y < HEIGHT)
	{

		i = 0;
		z_r = 4 * env->xmouse;
		z_i = 4 * env->ymouse;
		c_i = y / zoom_y + env->y1;
		c_r = x / zoom_x + env->x1;
		while (1)
		{
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i++;
			if (z_r * z_r + z_i*z_i >= 5 || i >= env->it)
				break;
		}
		if (i == env->it)
			env->data[y * WIDTH + x] = 0;
		else
		{
			env->data[y * WIDTH + x] = env->color * i / (int)env->it & env->color;
		}
		y++;
	}
}

void	ft_mandelbrot(t_env *env, int x, int xmax)
{
	double 	zoom_x;
	double 	zoom_y;

	zoom_x = HEIGHT /(env->x2 - env->x1) + env->xmouse;
	zoom_y = WIDTH /(env->y2 - env->y1) + env->ymouse;
	while (x < xmax && x < WIDTH)
	{
		ft_mandelbrot2(env, x, zoom_x, zoom_y);
		x++;
	}
}
