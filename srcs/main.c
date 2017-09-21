#include "fractol.h"

int   main(int ac, char **av)
{
  if (ac == 1 || ac > 2)
    ft_printf("Usage: ./fractol <fractol's name>\n");
  else
    ft_launcher(av[1]);
  return (0);
}
