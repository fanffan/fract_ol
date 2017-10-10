/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:05 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/10 12:36:32 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_mandelbrot(t_env *env)
{
  double zoom_x;
  double zoom_y;
  int x;
  int y;
  double tmp;

  zoom_x = env->x/(env->x2 - env->x1);
  zoom_y = env->y/(env->y2 - env->y1);
  x = 0;
  while (x < WIDTH)
  {
    y = 0;
    while (y < HEIGHT)
    {
      double c_r;
      double c_i;
      double z_r;
      double z_i;
      int i;

      z_r = 0;
      z_i = 0;
      i = 0;
      c_i = y / zoom_y + env->y1;
	  c_r = x / zoom_x + env->x1;
      while (1)
      {
        tmp = z_r;
        z_r = z_r*z_r - z_i*z_i + c_r;
        z_i = 2*z_i*tmp + c_i;
        i++;
        if (z_r*z_r + z_i*z_i >= 5 || i >= env->it)
          break;
      }
      if (i == env->it)
        env->data[y * 1000 + x] = 0xFFFFFF;
      else
        env->data[y * 1000 + x] = 0xFF0000;
      y++;
    }
    x++;
  }
  mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
