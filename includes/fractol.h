# ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1000
#define HEIGHT 1000

# include <mlx.h>
# include "../Libft/srclib/libft.h"
# include <pthread.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	double			flag;
	double			height;
	double			width;
	double			x;
	double			y;
	double			imgx;
	double			imgy;
	double			zoom;
	double			diff_x;
	double			diff_y;
	int				xmax;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			it;
	void			(*f)(struct s_env *env, int x, int xmax, int color);
	char			*name;
}					t_env;

int   ft_launcher(char *str);
void  ft_mandelbrot(t_env *env, int x, int xmax, int color);
void  ft_julia(t_env *env, int x, int xmax, int color);

# endif
