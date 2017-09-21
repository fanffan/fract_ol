#include "fractol.h"

int   ft_keyboard(int keycode, t_env *env)
{
  ft_printf("key:%d\n", keycode);
  if (keycode == 65451)
  {
    env->imgx += 50;
    env->imgy += 50;
    ft_printf("LOL\n");
    //mlx_clear_window(env->mlx, env->win);
    ft_mandelbrot(env, env->data);
  }
 return (0); 
}

int  ft_mouse(int button, int x,int y, t_env *env)
{
  ft_printf("buttton:%d x:%d y:%d\n",button, x, y);
  if (button == 4)
  {
    env->x = x;
    env->y = y;
    env->zoom += 1;
  }
  if (button == 5)
  {
    env->x = x;
    env->y = y;
    env->imgx -= 50;
    env->imgy -= 50;
  }
  ft_mandelbrot(env, env->data);
  return (0);
}

/*void   ft_choose_fract(t_env *env, char *str, int *data)
{
  if (ft_strcmp("Mandelbrot", str) == 0 || ft_strcmp("mandelbrot", str) == 0)
    ft_mandelbrot(env, data);
}*/

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
  if (ft_strcmp("Mandelbrot", str) == 0 || ft_strcmp("mandelbrot", str) == 0)
    ft_mandelbrot(env, env->data);
  //ft_choose_fract(env, str, data);
  mlx_key_hook(env->win, ft_keyboard, env);
  mlx_mouse_hook(env->win, ft_mouse, env);
  mlx_loop(env->mlx);
}

int   ft_launcher(char *str)
{
  t_env env;

  ft_bzero(&env, sizeof(t_env));
  env.imgx = 1000; 
  env.imgy = 1000; 
  ft_mlx(&env, str);
 return (0);
}
