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
void	slope_slow(t_bio **bio, t_values *values)
{
	float	y;

	values->delta = abs((*bio)->slope);
	y = (*bio)->y1;
	if ((*bio)->x2 < (*bio)->x1)
	{
		//printf("bio num before: x2[%i], x1[%i]", (*bio)->y2,(*bio)->y1);
		ft_int_swap((*bio)->x2,(*bio)->x1);
		//printf("bio num before: x2[%i], x1[%i]", (*bio)->y2,(*bio)->y1);
		y = (*bio)->y2;
	}
	//values->range = ((*bio)->x2 - (*bio)->x1);
	while ((*bio)->x1 < (*bio)->x2)
	{
		mlx_pixel_put((*bio)->mlx, (*bio)->window, (*bio)->x1, (*bio)->y1, WHITE);
		values->offset += values->delta;
		if(values->offset >= values->threshold)
		{
			y += values->adjust;
			values->threshold = 1.0;
		}
		(*bio)->x1++;
	}
}
void	slope_fast(t_bio **bio, t_values *values)
{	
	float	x;

	values->delta = abs((*bio)->slope);
	x = (*bio)->x1;
	if ((*bio)->y2 < (*bio)->y1)
	{
		//printf("bio num before: y2[%i], y1[%i]", (*bio)->y2,(*bio)->y1);
		ft_int_swap((*bio)->y2,(*bio)->y1);
		//printf("bio num after: y2[%i], y1[%i]", (*bio)->y2,(*bio)->y1);
		x = (*bio)->x2;
	}
	//values->range = ((*bio)->y2 - (*bio)->y1);
	while ((*bio)->y1 < (*bio)->y2)
	{
		mlx_pixel_put((*bio)->mlx, (*bio)->window, (*bio)->x1, (*bio)->y1, WHITE);
		values->offset += values->delta;
		if(values->offset >= values->threshold)
		{
			x += values->adjust;
			values->threshold = 1.0;
		}
	}
		(*bio)->y1++;
}

 void	slope_flat(t_bio **bio)
 {
	if (&(*bio)->y2 < &(*bio)->y1)
		ft_int_swap((*bio)->y1, (*bio)->y2);
	//printf("run is : x1[%d] x2[%d]", (*bio)->x1, (*bio)->x2);
	while ((*bio)->y1 <= (*bio)->y2)
	{
		mlx_pixel_put((*bio)->mlx, (*bio)->window, (*bio)->x1, (*bio)->y1, WHITE);
		(*bio)->y1++;				
	}
}