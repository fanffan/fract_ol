/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:20:48 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/20 10:04:17 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choose_mandel(t_env *env)
{
	if (!ft_strcmp("mandelbrot", env->name))
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_mandelbrot;
	}
	else if (!ft_strcmp("mandelbrot5", env->name))
	{
		env->x1 = -2.1 + 0.7;
		env->x2 = 0.6 + 0.7;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_mandelbrot5;
	}
	else if (!ft_strcmp("mandelbrot4", env->name))
	{
		env->x1 = -2.1 + 0.7;
		env->x2 = 0.6 + 0.7;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_mandelbrot4;
	}
}

void	ft_choose_burning(t_env *env)
{
	if (!ft_strcmp("burning_ship", env->name))
	{
		env->x1 = -2.1 + 0.7;
		env->x2 = 0.6 + 0.7;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_burning_ship;
	}
	else if (!ft_strcmp("burning_ship2", env->name))
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2 - 0.5;
		env->y2 = 1.2 - 0.5;
		env->f = ft_burning_ship2;
	}
}

void	ft_choose_other(t_env *env)
{
	if (!ft_strcmp("julia", env->name))
	{
		env->x1 = -1;
		env->x2 = 1;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_julia;
	}
	else if (!ft_strcmp("tricorne", env->name))
	{
		env->x1 = -2.1 + 0.5;
		env->x2 = 0.6 + 0.5;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_tricorne;
	}
	else if (!ft_strcmp("celtic_heart", env->name))
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->f = ft_celtic_heart;
	}
}

void	ft_choose_fract(t_env *env, char *str)
{
	if (!env->name)
		env->name = ft_strtolower(str);
	env->it = 40;
	if (env->name[0] == 'm')
		ft_choose_mandel(env);
	else if (env->name[0] == 'b')
		ft_choose_burning(env);
	else
		ft_choose_other(env);
	ft_fractol(env);
}
