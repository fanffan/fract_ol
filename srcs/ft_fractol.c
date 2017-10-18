/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:13:52 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/17 16:26:37 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_fra1(t_env *env)
{
	env->f(env, 0, WIDTH / 4);
	pthread_exit(NULL);
}

void	*ft_fra2(t_env *env)
{
	env->f(env, WIDTH / 4, WIDTH / 4 * 2);
	pthread_exit(NULL);
}

void	*ft_fra3(t_env *env)
{
	env->f(env, WIDTH / 4 * 2, WIDTH / 4 * 3);
	pthread_exit(NULL);
}

void	*ft_fra4(t_env *env)
{
	env->f(env, WIDTH / 4 * 3, WIDTH);
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
