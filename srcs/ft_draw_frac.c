/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/20 16:31:54 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_frac3(t_env *env, int x, int y, int i)
{
	if (i == env->it)
		env->data[y * WIDTH + x] = 0;
	else
		env->data[y * WIDTH + x] = env->color * i / (int)env->it & env->color;
}

void	ft_draw_frac2(t_env *env, int x, double zoom_x, double zoom_y)
{
	double	cr_ci[2];
	double	zr_zi[2];
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		if (env->name[0] == 'j')
		{
			cr_ci[0] = 0.285 + env->xmouse;
			cr_ci[1] = 0.01 + env->ymouse;
			zr_zi[0] = x / zoom_x + env->x1;
			zr_zi[1] = y / zoom_y + env->y1;
		}
		else
		{
			zr_zi[0] = 4 * env->xmouse;
			zr_zi[1] = 4 * env->ymouse;
			cr_ci[0] = x / zoom_x + env->x1;
			cr_ci[1] = y / zoom_y + env->y1;
		}
		ft_draw_frac3(env, x, y, env->f(env, zr_zi, cr_ci));
		y++;
	}
}

void	ft_draw_frac(t_env *env, int x, int xmax)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = HEIGHT / (env->x2 - env->x1);
	zoom_y = WIDTH / (env->y2 - env->y1);
	while (x < xmax && x < WIDTH)
	{
		ft_draw_frac2(env, x, zoom_x, zoom_y);
		x++;
	}
}
