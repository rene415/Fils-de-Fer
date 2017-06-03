/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:31:59 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/02 20:58:14 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
#define __FDF_H__

#include <unistd.h>
#include <stdio.h>
#include "mlx.h"

typedef struct	s_points
{
	int		x;
	int		y;
	int		z;
}				t_points;

int				my_key_funtion(int keycode, void *mlx);

#endif
