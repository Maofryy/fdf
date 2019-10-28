/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:57:54 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/28 18:28:43 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "mlx.h"

int	draw_line(void	*mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int x;
	int y;
	int ret;

	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	while (x != x2)
	{
		y = y1 + dy * (x - x1) / dx;
		ret = mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
		ft_putnbr(x);
		ft_putchar('\n');
		x++;
	}
	return (1);
}

int main(int ac, char **av)
{
	//int ***map;
	//t_fdf fdf;
	void *mlx_ptr;
	void *win_ptr;
	int draw_ret;

	//fdf_init(fdf);
	if (ac != 2)
	{
		ft_putstr("usage : ./fdf [map_file_name]\n");
		return (-1);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, av[1]);
	draw_ret = draw_line(mlx_ptr, win_ptr, 1, 1, 500, 200);
	ft_putstr("Finished drawing");
	mlx_loop(mlx_ptr);
	//fdf.av = ft_strdup(av[1]);
	//map = parse_file(fdf);

	return (0);
}
