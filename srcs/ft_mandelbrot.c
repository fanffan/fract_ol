#include "fractol.h"

void    ft_mandelbrot(t_env *env, int *data)
{
  double x1;
  double x2;
  double y1;
  double y2;
  double zoom_x;
  double zoom_y;
  int x;
  int y;
  double tmp;

  x1 = -2.1 / env->zoom;
  x2 = 0.6 / env->zoom;
  y1 = -1.2 / env->zoom;
  y2 = 1.2 / env->zoom;
  zoom_x = env->imgx/(x2 - x1);
  zoom_y = env->imgy/(y2 - y1);
  x = 0;
  while (x < env->imgx && x < WIDTH)
  {
    y = 0;
    while (y < env->imgy && y < HEIGHT)
    {
      double c_r = x / zoom_x + x1;
      double c_i = y / zoom_y + y1;
      double z_r = 0;
      double z_i = 0;
      int i = 0;
      while (1)
      {
        tmp = z_r;
        z_r = z_r*z_r - z_i*z_i + c_r;
        z_i = 2*z_i*tmp + c_i;
        i++;
        if (z_r*z_r + z_i*z_i >= 4 || i >= IT_MAX)
          break;
      }
      if (i == IT_MAX)
        data[y * 1000 + x] = 0xFFFFFF;
      else
        data[y * 1000 + x] = 0;
      y++;
    }
    x++;
  }
  mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);

}
