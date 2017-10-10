#include "fractol.h"

/*int   ft_keyboard(int keycode, t_env *env)
{
  ft_printf("key:%d\n", keycode);
 return (0); 
}*/

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
  ft_mandelbrot(env, 0, WIDTH);
  return (0);
}

void	ft_mand1(t_env *env, int x)
{
	ft_printf("x:%d\n", x);
	ft_mandelbrot(env, 0, WIDTH / 4);
}

void	ft_mand2(t_env *env, int x)
{
	ft_printf("x:%d\n", x);
	ft_mandelbrot(env, WIDTH / 4, WIDTH / 3);
}

void	ft_fractol(void (**f)(t_env *), t_env *env)
{
	pthread_t	thread1;
	pthread_t	thread2;

	ft_printf("lol\n");
	if (pthread_create(&thread1, NULL, (void *)f[0], env) == -1 ||
			pthread_create(&thread2, NULL, (void *)f[1], env) == -1)
	{
		ft_putstr("pthread error");
		return ;
	}
	if (pthread_join(thread1, NULL))
	{
		ft_putstr("pthread_join");
		return;
	}
}

void   ft_choose_fract(t_env *env, char *str)
{
	void	mand[2];

	mand[0] = ft_mand1;
	mand[1] = ft_mand2;
	if (ft_strcmp("Mandelbrot", str) == 0 || ft_strcmp("mandelbrot", str) == 0)
	{
		env->x = 1000; 
		env->y = 1000; 
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->it = 50;
		ft_fractol(mand, env);
	}
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
	//mlx_key_hook(env->win, ft_keyboard, env);
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
