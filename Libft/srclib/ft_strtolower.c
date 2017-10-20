/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:02:50 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/20 11:23:06 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = ft_strnew(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		cpy[i] = ft_tolower(str[i]);
		i++;
	}
	return (cpy);
}
