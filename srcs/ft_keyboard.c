/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:32:59 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 18:40:03 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_cross(void)
{
	exit(0);
	return (0);
}

void	ft_switch(int keycode, t_env *env)
{
if (!env->name)
		ft_strdel(&env->name);
	if (keycode == 18)
		ft_choose_fract(env, "julia");
	if (keycode == 19)
		ft_choose_fract(env, "mandelbrot");
	if (keycode == 20)
		ft_choose_fract(env, "mandelbrot4");
	if (keycode == 21)
		ft_choose_fract(env, "mandelbrot5");
	if (keycode == 23)
		ft_choose_fract(env, "burning_ship");
	if (keycode == 22)
		ft_choose_fract(env, "burning_ship2");
	if (keycode == 26)
		ft_choose_fract(env, "tricorne");
	if (keycode == 28)
		ft_choose_fract(env, "celtic_heart");
}

void	ft_color(int keycode, t_env *env)
{
	if (keycode == 8)
	{
		if (env->i == 0)
			env->color = 0x00FF00;
		else if (env->i == 1)
			env->color = 0xFF0000;
		if (env->i == 2)
		{
			env->color = 0x0000FF;
			env->i = -1;
		}
		env->i++;
		ft_fractol(env);
	}
	if (keycode == 46)
	{
		if (env->i == 0)
			env->color = 0x000FF0;
		else if (env->i == 1)
			env->color = 0x0FF000;
		if (env->i == 2)
		{
			env->color = 0xFFFF0F;
			env->i = -1;
		}
		env->i++;
		ft_fractol(env);
	}
}

int		ft_keyboard(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_cross();
	if (keycode == 15)
	{
		env->xmouse = 0;
		env->ymouse = 0;
		ft_choose_fract(env, env->name);
	}
	if (keycode == 1)
	{
		if (env->stop == 0)
			env->stop = 1;
		else
			env->stop = 0;
	}
	ft_color(keycode, env);
	ft_switch(keycode, env);
	return (0);
}
