/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:42:10 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/04 10:54:09 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_set_sizex(t_map *map, int i)
{
	if (map->sizex != i && map->sizex != 0)
	{
		map->error = 1;
		ft_putstr_fd("FdF : wrong file format. \n", 2);
		exit(1);
	}
	map->sizex = i;
	return (map);
}

static	void	atoi_tab(char **tab, t_map *map)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (tab[n])
		++n;
	while (tab[i])
	{
		map->data[map->sizey * n + i] = ft_atoi(tab[i]);
		++i;
	}
	ft_set_sizex(map, i);
}

t_map			*ft_parsemap(char *str, t_map *map)
{
	char	*line;
	char	**tab;
	int		fd;
	off_t	size;

	size = 0;
	if ((fd = open(str, O_RDONLY)) > 0)
		while (get_next_line(fd, &line) > 0)
		{
			size += ft_strlen(line);
			free(line);
		}
	map->data = (int *)malloc(size * sizeof(int));
	if ((fd = open(str, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			atoi_tab(tab, map);
			free(line);
			ft_free_tab(&tab);
			map->sizey++;
		}
	}
	return (map);
}
