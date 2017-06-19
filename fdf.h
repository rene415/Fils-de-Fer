/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:31:59 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/05 11:59:42 by rramirez         ###   ########.fr       */
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
	void		*mlx;
	void		*points;
}			t_fdf;

int				my_key_funtion(int keycode, void *mlx);

#endif
