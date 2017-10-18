/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:20:46 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/18 16:51:13 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1000
#define HEIGHT 1000

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
	double			flag;
	double			height;
	double			width;
	double			xmouse;
	double			ymouse;
	double			imgx;
	double			imgy;
	double			zoom;
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
	void			(*f)(struct s_env *env, int x, int xmax);
	char			*name;
}					t_env;

int		ft_launcher(char *str);
void	ft_fractol(t_env *env);
void	ft_julia(t_env *env, int x, int xmax);
void	ft_mandelbrot(t_env *env, int x, int xmax);
void	ft_mandelbrot5(t_env *env, int x, int xmax);
void	ft_mandelbrot4(t_env *env, int x, int xmax);
void	ft_burning_ship(t_env *env, int x, int xmax);
void	ft_burning_ship2(t_env *env, int x, int xmax);
void	ft_celtic_heart(t_env *env, int x, int xmax);
void	ft_tricorne(t_env *env, int x, int xmax);

# endif
