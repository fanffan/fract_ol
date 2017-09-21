# ifndef FRACTOL_H
# define FRACTOL_H

#define IT_MAX 50
#define WIDTH 1000
#define HEIGHT 1000

#include "../Libft/srclib/libft.h"
#include "../mlx/mlx.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
  void      *img;
  int       *data;
  int       flag;
	int				height;
	int				width;
  int       x;
  int       y;
  int       imgx;
  int       imgy;
  int       zoom;
}					t_env;

int   ft_launcher(char *str);
void  ft_mandelbrot(t_env *env, int *data);

# endif
