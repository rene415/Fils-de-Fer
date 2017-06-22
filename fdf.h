/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:31:59 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/22 16:30:23 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
#define __FDF_H__

#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
#include "mlx.h"
#include "libft/libft.h"

typedef struct		s_points
{
	int		x;
	int		y;
	int		z;
}			t_points;

typedef struct		s_fdf
{
	int		width;
	int		height;
	int		**map;
}			t_fdf;

int				my_key_funtion(int keycode, void *mlx);
void			save_file(char **argv, t_fdf *size);
int				ft_width(char **file);
void			coordinates(int fd, t_fdf size);
#endif
