/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:20:46 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/20 16:42:32 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000
# define NBTHREAD 8

# include <mlx.h>
# include "../Libft/srclib/libft.h"
# include <pthread.h>
# include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				stop;
	double			xmouse;
	double			ymouse;
	double			diff_x;
	double			diff_y;
	int				xmax;
	int				color;
	int				i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			it;
	int				(*f)(struct s_env *env, double *zr_zi, double *cr_ci);
	char			*name;
}					t_env;

typedef struct		s_thread
{
	t_env			*env;
	int				i;
}					t_thread;

int					ft_launcher(char *str);
int					ft_keyboard(int keycode, t_env *env);
void				ft_fractol(t_env *env);
void				ft_draw_frac(t_env *env, int x, int xmax);
void				ft_choose_fract(t_env *env, char *str);
int					ft_julia(t_env *env, double *zr_zi, double *cr_ci);
int					ft_mandelbrot(t_env *env, double *zr_zi, double *cr_ci);
int					ft_mandelbrot4(t_env *env, double *zr_zi, double *cr_ci);
int					ft_mandelbrot5(t_env *env, double *zr_zi, double *cr_ci);
int					ft_burning_ship(t_env *env, double *zr_zi, double *cr_ci);
int					ft_burning_ship2(t_env *env, double *zr_zi, double *cr_ci);
int					ft_celtic_heart(t_env *env, double *zr_zi, double *cr_ci);
int					ft_tricorne(t_env *env, double *zr_zi, double *cr_ci);
int					ft_cross(t_env *env);

#endif
