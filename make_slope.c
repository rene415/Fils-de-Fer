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

	//printf("fast slope\n");
	values->delta = fabsf(bio->slope);
	//printf("delta is [%f]", *(values)->delta);
	x = bio->x1;
	//printf("x is [%f]\n", x);
	if (bio->y2 < bio->y1)
	{
		//printf("fast slope bio num before: y2[%i], y1[%i]\n", bio->y2,bio->y1);
		tmp = bio->y2;
		bio->y2 = bio->y1;
		bio->y1 = tmp;
		//printf("fast slope bio num after: y2[%i], y1[%i]\n", bio->y2,bio->y1);
		x = bio->x2;
	}
	//values->range = (bio->y2 - bio->y1);
	while (bio->y1 < bio->y2)
	{
		mlx_pixel_put(bio->mlx, bio->window, x, bio->y1, RED);
		values->offset += values->delta;
		if(values->offset >= values->threshold)
		{
			//printf("offset is [%f]___ delta is [%f]___ threshold is [%f] \n", values->offset, values->delta, values->offset);
			x += values->adjust;
			values->threshold += 1.0;
		}
		//printf("before y is [%f]\n", bio->y1);
		bio->y1++;
		//printf("after y is [%f]\n\n", bio->y1);
	}
	//printf("inside fast slope\n");
}
void	slope_slow(t_bio *bio, t_values *values)
{
	float	y;
	float	tmp;

	//printf("inside slow\n");
	values->delta = fabsf(bio->slope);
	//printf("delta is [%f]\n", values->delta);
	y = bio->y1;
	//printf("y is [%f]\n", y);
	if (bio->x2 < bio->x1)
	{
		//printf("slow slope bio num before: x2[%i], x1[%i]\n", bio->x2,bio->x1);
		tmp = bio->x2;
		bio->x2 = bio->x1;
		bio->x1 = tmp;
		y = bio->y2;
		//printf("slow slope bio num after: x2[%i], x1[%i]\n", bio->x2,bio->x1);
	}
	//values->range = (bio->x2 - bio->x1);
	while (bio->x1 < bio->x2)
	{
		mlx_pixel_put(bio->mlx, bio->window, bio->x1, y, WHITE);
		values->offset += values->delta;
		//printf("AFTER: offset is [%f]___ delta is [%f]___ threshold is [%f] \n", values->offset, values->delta, values->threshold);
		if(values->offset >= values->threshold)
		{
			//printf("BEFORE: offset is [%f]___ delta is [%f]___ threshold is [%f] \n", values->offset, values->delta, values->threshold);
			y += values->adjust;
			values->threshold += 1.0;
		}
		//printf("before x is [%f]\n", bio->x1);
		bio->x1++;
		//printf("after x is [%f]\n\n", bio->x1);
	}
	//printf("inside slow slope\n");
}
void	slope_flat(t_bio *bio)
 {
 	float	tmp;

	//printf("----------inside flat----------\n");
	if (bio->y2 < bio->y1)
	{
		//printf("******************\n");
		//printf("no slope before is : x1[%d] x2[%d]", bio->x1, bio->x2);
		tmp = bio->y2;
		bio->y2 = bio->y1;
		bio->y1 = tmp;
		//printf("no slope after is : x1[%d] x2[%d]", bio->x1, bio->x2);
	}
	while (bio->y1 <= bio->y2)
	{
		//printf("inside slope straight\n");
		mlx_pixel_put(bio->mlx, bio->window, bio->x1, bio->y1, WHITE);
		bio->y1++;				
	}
}