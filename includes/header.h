/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:57:17 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/29 14:40:25 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include "libft.h"
# define X_WINDOW 1400
# define Y_WINDOW 700


typedef struct	s_2Ddot
{
	int x;
	int y;
}				t_2Ddot;

typedef struct	s_3Ddot
{
	int x;
	int y;
	int z;
}				t_3Ddot;


typedef struct	s_fdf
{
	char	*filename;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int	***parse_file(int fd);
t_2Ddot new_2Ddot(int x, int y);
t_3Ddot new_3Ddot(int x, int y, int z);
void	put_dot(t_2Ddot);

#endif
