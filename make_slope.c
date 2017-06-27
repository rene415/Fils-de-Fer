/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_slope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:44:33 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/24 21:44:45 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slope_fast(t_bio *bio, t_values *values)
{	
	float	x;
	float	tmp;

	values->delta = fabsf(bio->run/bio->rise);
	x = bio->x1;
	if (bio->y2 < bio->y1)
	{
		tmp = bio->y2;
		bio->y2 = bio->y1;
		bio->y1 = tmp;
		x = bio->x2;
	}
	printf("y1[%f]->y2[%f]\n", bio->y1, bio->y2);
	while(bio->y1 < bio->y2)
	{
		mlx_pixel_put(bio->mlx, bio->window, x, bio->y1, BLUE);
		values->offset += values->delta;
		if(values->offset >= values->threshold)
		{
			x += values->adjust;
			values->threshold += 1.0;
		}
		bio->y1++;
	}
}

void	slope_slow(t_bio *bio, t_values *values)
{
	float	y;
	float	tmp;

	values->delta = fabsf(bio->slope);
	y = bio->y1;
	if (bio->x2 < bio->x1)
	{
		tmp = bio->x2;
		bio->x2 = bio->x1;
		bio->x1 = tmp;
		y = bio->y2;
	}
	while (bio->x1 < bio->x2)
	{
		mlx_pixel_put(bio->mlx, bio->window, bio->x1, y, WHITE);
		values->offset += values->delta;
		if(values->offset >= values->threshold)
		{
			y += values->adjust;
			values->threshold += 1.0;
		}
		bio->x1++;
	}
}

void	slope_flat(t_bio *bio)
 {
 	float	tmp;

	if (bio->y2 < bio->y1)
	{
		tmp = bio->y2;
		bio->y2 = bio->y1;
		bio->y1 = tmp;
		
	}
	while (bio->y1 <= bio->y2)
	{
		mlx_pixel_put(bio->mlx, bio->window, bio->x1, bio->y1, RED);
		bio->y1++;				
	}
}