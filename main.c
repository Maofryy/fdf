/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:57:54 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/28 18:14:32 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "mlx.h"

int main(int ac, char **av)
{
	//int ***map;
	//t_fdf fdf;
	void *mlx_ptr;
	void *win_ptr;
	int ret;

	//fdf_init(fdf);
	if (ac != 2)
	{
		ft_putstr("usage : ./fdf [map_file_name]\n");
		return (-1);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, av[1]);
	ret = mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xffffffff, av[1]);

	mlx_loop(mlx_ptr);
	//fdf.av = ft_strdup(av[1]);
	//map = parse_file(fdf);

	return (0);
}
