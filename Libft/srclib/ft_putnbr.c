/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:28:39 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 13:48:18 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int n1;

	n1 = (long int)n;
	if (n1 < 0)
	{
		ft_putchar('-');
		n1 = n1 * -1;
	}
	if (n1 >= 10)
	{
		ft_putnbr(n1 / 10);
	}
	ft_putchar((n1 % 10) + 48);
}