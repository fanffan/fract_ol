/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:13:52 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/19 17:49:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_fra(t_thread *thr)
{
	ft_draw_frac(thr->env, WIDTH / NBTHREAD * thr->i, WIDTH / NBTHREAD
			* (thr->i + 1));
	pthread_exit(NULL);
}

void	ft_fractol(t_env *env)
{
	pthread_t	thread[NBTHREAD];
	t_thread	thr[NBTHREAD];
	int			i;

	i = 0;
	while (i < NBTHREAD)
	{
		thr[i].env = env;
		thr[i].i = i;
		pthread_create(&thread[i], NULL, (void*)ft_fra, &thr[i]);
		i++;
	}
	while (i >= 0)
	{
		pthread_join(thread[i], NULL);
		i--;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
