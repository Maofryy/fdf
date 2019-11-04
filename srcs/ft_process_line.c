/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:42:18 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/04 14:02:52 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free_tab(char ***s)
{
	size_t	i;

	i = 0;
	if (s == NULL || *s == NULL)
		return ;
	while ((*s)[i])
	{
		free((*s)[i]);
		i++;
	}
	free(*s);
}

void		ft_process_line(t_map *map)
{
	map->d2 = map->d * 2;
	if (map->d2 >= map->my)
	{
		map->d += map->my;
		map->x1 += map->signx;
	}
	if (map->d2 <= map->mx)
	{
		map->d += map->mx;
		map->y1 += map->signy;
	}
}
