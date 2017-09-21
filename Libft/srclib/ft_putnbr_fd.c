/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:28:39 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 13:54:35 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int n1;

	n1 = (long int)n;
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = n1 * -1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd(n1 / 10, fd);
	}
	ft_putchar_fd((n1 % 10) + 48, fd);
}