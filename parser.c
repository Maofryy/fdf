/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:53:33 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/28 14:00:29 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	***parse_file(t_fdf fdf)
{
	char	**file;
	int		i;
	int fd;

	i = 0;
	file = (char **)malloc(sizeof(char *) * 2);
	fd = open(fdf.filename, O_RDONLY);
	while (get_next_line(fd, &file[i]))
	{
	}
}
