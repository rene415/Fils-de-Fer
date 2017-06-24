/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:31:59 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/23 18:56:27 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
#define __FDF_H__

#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
//#include "mlx.h"
#include "libft/libft.h"

typedef	struct		s_cartp
{
	double		x;
	double		y;
	double		z;
	//double		raw_z;
}			t_cartp;

typedef struct		s_bio
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		gap;
	int		big;
	int 		rise;
	int		run;
	int		slope;
	int 		max;
	int		smax;
	void		*mlx;
	void		*window;
	int		midx;
	int		midy;
}			t_bio;

typedef struct		s_fdf
{
	int		zmax;
	int		zmin;
	int		width;
	int		height;
	int		**map;
}			t_fdf;

int			my_key_funtion(int keycode, void *mlx);
void			save_file(char **argv, t_fdf *size);
void			coordinates(int fd,char **argv,  t_fdf size);
void			make_env(t_fdf size);
void			value_z(t_fdf *size, int x);
#endif
