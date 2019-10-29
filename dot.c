/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:00:09 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/29 11:46:48 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_2Ddot		new_2Ddot(int x, int y)
{
	t_2Ddot d;
	
	d.x = x;
	d.y = y;
	return (d);
}

t_3Ddot		new_3Ddot(int x, int y, int z)
{
	t_3Ddot d;
	
	d.x = x;
	d.y = y;
	d.z = z;
	return (d);
}

void	put_dot(t_2Ddot d)
{
	ft_putstr("Dot = x : ");
	ft_putnbr(d.x);
	ft_putstr(" , y : ");
	ft_putnbr(d.y);
	ft_putchar('\n');
}
