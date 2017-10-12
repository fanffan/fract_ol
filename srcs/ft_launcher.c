#include "fractol.h"

int			ft_cross(void)
{
	exit(0);
	return (0);
}

void	*ft_fra1(t_env *env)
{
	env->f(env, 0, 250, 0xFFFFFF);
	pthread_exit(NULL);
}

void	*ft_fra2(t_env *env)
{
	env->f(env, 250, 500, 0xFFFFFF);
	pthread_exit(NULL);
}

void	*ft_fra3(t_env *env)
{
	env->f(env, 500, 750, 0xFFFFFF);
	pthread_exit(NULL);
}

void	*ft_fra4(t_env *env)
{
	env->f(env, 750, 1000, 0xFFFFFF);
	pthread_exit(NULL);
}

void	ft_fractol(t_env *env)
{
	pthread_t	thread[4];
	void		(*fra[4])(t_env*);
	int			i;

	i = 0;
	fra[0] = (void*)ft_fra1;
	fra[1] = (void*)ft_fra2;
	fra[2] = (void*)ft_fra3;
	fra[3] = (void*)ft_fra4;
	while (i < 4)
	{
		pthread_create(&thread[i], NULL, (void*)fra[i], env);
		i++;
	}
	while (i >= 0)
	{
		pthread_join(thread[i], NULL);
		i--;
	}
  mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int  ft_mouse(int button, int x,int y, t_env *env)
{
	ft_printf("buttton:%d x:%d y:%d\n",button, x, y);
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

void   ft_choose_fract(t_env *env, char *str)
{

	if (!ft_strcmp("Mandelbrot", str) || !ft_strcmp("mandelbrot", str))
	{
		env->x = 1000; 
		env->y = 1000; 
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 25;
		env->f = ft_mandelbrot;
		env->name = str;
		ft_fractol(env);
	}
	if (!ft_strcmp("Julia", str) || !ft_strcmp("julia", str))
	{
		env->x = 1000; 
		env->y = 1000; 
		env->x1 = -1;
		env->x2 = 1;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 25;
		env->f = ft_julia;
		env->name = str;
		env->f = ft_mandelbrot;
		env->name = str;
		ft_fractol(env);
	}
}

int   ft_keyboard(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_cross();
	if (keycode == 15)
		ft_choose_fract(env, env->name);
	ft_printf("key:%d\n", keycode);
	return (0); 
}

void  ft_mlx(t_env *env, char *str)
{
	int			size_l;
	int			bpp;
	int	endian;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1000, 1000, "Fractol");
	env->img = mlx_new_image(env->mlx, 1000, 1000);
	env->data = (int *)mlx_get_data_addr(env->img, &bpp, &size_l, &endian);
	env->zoom = 1;
	ft_choose_fract(env, str);
	mlx_key_hook(env->win, ft_keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), ft_cross, env);
	mlx_mouse_hook(env->win, ft_mouse, env);
	mlx_loop(env->mlx);
}

int   ft_launcher(char *str)
{
	t_env env;

	ft_bzero(&env, sizeof(t_env));
	ft_mlx(&env, str);
	return (0);
}
