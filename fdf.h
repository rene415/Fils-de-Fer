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

typedef	struct		s_values
{
	float		offset;
	float		threshold;
	float		delta;
	float		adjust;
}				t_values;

typedef	struct		s_cartp
{
	float		x;
	float		y;
	float		z;
	//double		raw_z;
}				t_cartp;

typedef struct		s_bio
{
	int		k;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		gap;
	int		big;
	int 		rise;
	int		run;
	int		slope;
	float		max;
	float		smax;
	void		*mlx;
	void		*window;
	int		midx;
	int		midy;
	t_cartp		**cart;
}			t_bio;

typedef struct		s_fdf
{
	int		zmax;
	int		zmin;
	int		width;
	int		height;
	int		**map;
}			t_fdf;

int				my_key_funtion(int keycode, void *mlx);
void			save_file(char **argv, t_fdf *size);
void			coordinates(int fd,char **argv,  t_fdf **size);
void			value_z(t_fdf **size, int x);
t_bio			*make_env(t_fdf size);
t_cartp			**ft_make_cart(t_bio **bio, t_fdf size);
void			draw_pieces(t_bio *bio, t_fdf size);
void			translate(t_bio **bio, t_fdf size);
void			ft_values(t_fdf size, t_bio **bio, int i, int j);
void			draw_right(t_fdf size, t_bio *bio, t_values **values);
void			draw_down(t_fdf size, t_bio *bio, t_values **values);
void			slope_slow(t_fdf size, t_bio **bio, t_values *values);
void			slope_fast(t_fdf size, t_bio **bio, t_values *values);
void			slope_flat(t_fdf size, t_bio **bio);
#endif
