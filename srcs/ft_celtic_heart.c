/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_celtic_heart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/18 15:20:07 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_celtic_heart2(t_env *env, int x, double zoom_x, double zoom_y)
{
	double	c_r;
	double 	c_i;
	double 	z_r;
	double 	z_i;
	double 	tmp;
	int 	i;
	int 	y;

	y = 0;
	while (y < HEIGHT)
	{

		i = 0;
		z_r = 0; 
		z_i = 0;
		c_i = y / zoom_y + env->y1;
		c_r = x / zoom_x + env->x1;
		while (1)
		{
			tmp = z_r;
			z_r = fabs(z_r * z_r - z_i * z_i) + c_r;
			z_i = fabs(tmp) * z_i * 2 + c_i;
			i++;
			if (z_r * z_r + z_i*z_i >= 5 || i >= env->it)
				break;
		}
		if (i == env->it)
			env->data[y * WIDTH + x] = 0;
		else
			env->data[y * WIDTH + x] = 0x0000FF * i / env->it;
		y++;
	}
}

void	ft_celtic_heart(t_env *env, int x, int xmax)
{
	double 	zoom_x;
	double 	zoom_y;

	zoom_x = HEIGHT /(env->x2 - env->x1) + env->xmouse;
	zoom_y = WIDTH /(env->y2 - env->y1) + env->ymouse;
	while (x < xmax && x < WIDTH)
	{
		ft_celtic_heart2(env, x, zoom_x, zoom_y);
		x++;
	}
}
