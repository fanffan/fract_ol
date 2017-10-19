/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:29:23 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 18:38:12 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_cross(void)
{
	exit(0);
	return (0);
}

int		ft_mouse(int button, int x, int y, t_env *env)
{
	if (button == 1 || button == 5)
	{
		env->diff_y = (env->y2 - env->y1) * 0.2;
		env->diff_x = (env->x2 - env->x1) * 0.2;
		env->y1 = (env->y1 + env->diff_y * (double)y / HEIGHT);
		env->y2 = (env->y2 - env->diff_y * (1 - ((double)y / HEIGHT)));
		env->x1 = (env->x1 + env->diff_x * (double)x / WIDTH);
		env->x2 = (env->x2 - env->diff_x * (1 - ((double)x / WIDTH)));
		env->it += 1;
	}
	if (button == 2 || button == 6)
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
		ft_fractol(env);
	}
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
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	env.color = 0x0000FF;
	ft_mlx(&env, str);
	return (0);
}
