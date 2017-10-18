/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:29:23 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/18 16:57:39 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_cross(void)
{
	exit(0);
	return (0);
}

int		ft_mouse(int button, int x, int y, t_env *env)
{
	ft_printf("buttton:%d x:%d y:%d\n", button, x, y);
	if (button == 1)
	{
		env->diff_y = (env->y2 - env->y1) * 0.2;
		env->diff_x = (env->x2 - env->x1) * 0.2;
		env->y1 = (env->y1 + env->diff_y * (double)y / HEIGHT);
		env->y2 = (env->y2 - env->diff_y * (1 - ((double)y / HEIGHT)));
		env->x1 = (env->x1 + env->diff_x * (double)x / WIDTH);
		env->x2 = (env->x2 - env->diff_x * (1 - ((double)x / WIDTH)));
		env->it += 1;
	}
	if (button == 2)
	{
		env->diff_y = (env->y2 - env->y1) * 0.2;
		env->diff_x = (env->x2 - env->x1) * 0.2;
		env->y1 = (env->y1 - env->diff_y * (double)y / HEIGHT);
		env->y2 = (env->y2 + env->diff_y * (1 - ((double)y / HEIGHT)));
		env->x1 = (env->x1 - env->diff_x * (double)x / WIDTH);
		env->x2 = (env->x2 + env->diff_x * (1 - ((double)x / WIDTH)));
		env->it -= 1;
	}
	ft_fractol(env);
	return (0);
}

int		ft_hook(int x, int y, t_env *env)
{
	if (env->stop)
	{
		env->xmouse = (double)x / ((double)HEIGHT * 4);
		env->ymouse = (double)y / ((double)WIDTH * 4);
		ft_printf("x:%d, y:%d\n", x, y);
		ft_fractol(env);
	}
	return (0);
}

void	ft_choose_fract(t_env *env, char *str)
{
	env->name = ft_strtolower(str);
	if (!ft_strcmp("mandelbrot", env->name))
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 40;
		env->f = ft_mandelbrot;
		ft_fractol(env);
	}
	else if (!ft_strcmp("julia", env->name))
	{
		env->x1 = -1;
		env->x2 = 1;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		env->f = ft_julia;
		ft_fractol(env);
	}
	else if (!ft_strcmp("mandelbrot5", env->name))
	{
		env->x1 = -2.1 + 0.7;
		env->x2 = 0.6 + 0.7;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		env->f = ft_mandelbrot5;
		ft_fractol(env);
	}
	else if (!ft_strcmp("mandelbrot4", env->name))
	{
		env->x1 = -2.1 + 0.7;
		env->x2 = 0.6 + 0.7;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		env->f = ft_mandelbrot4;
		ft_fractol(env);
	}
	else if (!ft_strcmp("burning_ship", env->name))
	{
		env->x1 = -2.1 + 0.7;
		env->x2 = 0.6 + 0.7;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		env->f = ft_burning_ship;
		ft_fractol(env);
	}
	else if (!ft_strcmp("tricorne", env->name))
	{
		env->x1 = -2.1 + 0.5;
		env->x2 = 0.6 + 0.5;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		env->f = ft_tricorne;
		ft_fractol(env);
	}
	else if (!ft_strcmp("burning_ship2", env->name))
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2 - 0.5;
		env->y2 = 1.2 - 0.5;
		env->it = 50;
		env->f = ft_burning_ship2;
		ft_fractol(env);
	}
	else if (!ft_strcmp("celtic_heart", env->name))
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		env->f = ft_celtic_heart;
		ft_fractol(env);
	}
}

int		ft_keyboard(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_cross();
	if (keycode == 15)
		ft_choose_fract(env, env->name);
	if (keycode == 1)
	{
		if (env->stop == 0)
			env->stop = 1;
		else
			env->stop = 0;
	}
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
		ft_fractol(env);
		env->i++;
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
		ft_fractol(env);
		env->i++;
		ft_fractol(env);
	}
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
	ft_printf("key:%d stop:%d\n", keycode, env->stop);
	return (0); 
}

void	ft_mlx(t_env *env, char *str)
{
	int			size_l;
	int			bpp;
	int			endian;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fractol");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = (int *)mlx_get_data_addr(env->img, &bpp, &size_l, &endian);
	env->zoom = 1;
	ft_choose_fract(env, str);
	mlx_key_hook(env->win, ft_keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), ft_cross, env);
	mlx_hook(env->win, 6, (6L << 0), ft_hook, env);
	mlx_mouse_hook(env->win, ft_mouse, env);
	mlx_loop(env->mlx);
}

int		ft_launcher(char *str)
{
	t_env 		env;

	ft_bzero(&env, sizeof(t_env));
	env.color = 0x0000FF;
	ft_mlx(&env, str);
	return (0);
}
