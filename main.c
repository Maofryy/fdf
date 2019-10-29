/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:57:54 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/29 14:40:22 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "mlx.h"

int	draw_line(t_fdf fdf, t_2Ddot d1, t_2Ddot d2, int color)
{
	t_2Ddot D;
	t_2Ddot M;
	int ret;

	D = new_2Ddot(d2.x - d1.x, d2.y - d1.y);
	M = new_2Ddot(d1.x, d1.y);
	while (M.x != d2.x)
	{
		M.y = d1.y + D.y * (M.x - d1.x) / D.x;
		ret = mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, M.x, M.y, color);
		M.x++;
	}
	while (M.y != d2.y)
	{
		ret = mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, M.x, M.y, color);
		M.y++;
	}
	return (1);
}

int	draw_text(t_fdf fdf, t_2Ddot d, int color, char *text)
{
	int ret;

	ret = mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, d.x, d.y, color, text);
	return (ret);
}


int main(int ac, char **av)
{
	t_fdf fdf;

	//fdf_init(fdf);
	int i = 0;
	int j;
	int nx = 5;
	int ny = 5;
	t_3Ddot map[nx][ny]; 

	// INIT WINDOW
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, X_WINDOW, Y_WINDOW, av[1]);

	// INIT MAP
	while (i < nx)
	{
		j = 0;
		while (j < ny)
		{
			map[i][j] = new_3Ddot((X_WINDOW * i) / (2 * nx) + X_WINDOW / 4, (Y_WINDOW * j) / (2 * ny) + Y_WINDOW / 4, 0);
			mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, map[i][j].x, map[i][j].y, 0xffffff);
			j++;
		}
		i++;
	}

	if (ac != 2)
	{
		ft_putstr("usage : ./fdf [map_file_name]\n");
		return (-1);
	}

	
	//DRAW EDGE LINES
	draw_line(fdf, new_2Ddot(map[nx - 1][0].x, map[nx - 1][0].y), new_2Ddot(map[nx - 1][ny - 1].x, map[nx - 1][ny - 1].y), 0xffffff); 
	draw_line(fdf, new_2Ddot(map[0][ny - 1].x, map[0][ny - 1].y), new_2Ddot(map[nx - 1][ny - 1].x, map[nx - 1][ny - 1].y), 0xffffff); 
	
	//DRAW IN BETWEEN LINES
	
	i = 0;
	while (i < nx - 1)
	{
		j = 0;
		while (j < ny - 1)
		{
			//put_dot(new_2Ddot(map[i][j].x, map[i][j].y));
			//put_dot(new_2Ddot(map[i+1][j].x, map[i+1][j].y));
			//put_dot(new_2Ddot(map[i][j+1].x, map[i][j+1].y));
			draw_line(fdf, new_2Ddot(map[i][j].x, map[i][j].y), new_2Ddot(map[i + 1][j].x, map[i + 1][j].y), 0xffffff); 
			draw_line(fdf, new_2Ddot(map[i][j].x, map[i][j].y), new_2Ddot(map[i][j + 1].x, map[i][j + 1].y), 0xffffff); 
			j++;
		}
		i++;
	}

	mlx_loop(fdf.mlx_ptr);
	//fdf.av = ft_strdup(av[1]);
	//map = parse_file(fdf);

	return (0);
}
