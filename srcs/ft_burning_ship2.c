/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/18 14:52:30 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burning_ship2_2(t_env *env, int x, double zoom_x, double zoom_y)
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

		z_r = 0;
		z_i = 0;
		i = 0;
		c_i = y / zoom_y + env->y1;
		c_r = x / zoom_x + env->x1;
		while (1)
		{
			tmp = z_r;
			z_rt = z_r * z_r;
			z_it = z_i * z_i;
			z_r = z_rt - z_it + c_r; 
			z_i = fabs(tmp * z_i) * 2 + c_i;
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

void	ft_burning_ship2(t_env *env, int x, int xmax)
{
	double 	zoom_x;
	double 	zoom_y;

	zoom_x = HEIGHT /(env->x2 - env->x1);
	zoom_y = WIDTH /(env->y2 - env->y1);
	while (x < xmax && x < WIDTH)
	{
		ft_burning_ship2_2(env, x, zoom_x, zoom_y);
		x++;
	}
}