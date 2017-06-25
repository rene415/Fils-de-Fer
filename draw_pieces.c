/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 08:46:10 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/24 08:46:20 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_values(t_bio **bio, int i, int j)
{
	(*bio)->x1 = round((*bio)->cart[i][j].x);
	(*bio)->y1 = round((*bio)->cart[i][j].y);
	if((*bio)->k == 1)
	{
		(*bio)->x2 = round((*bio)->cart[i][j + 1].x);
		(*bio)->y2 = round((*bio)->cart[i][j + 1].y);
	}
	else
	{
		(*bio)->x2 = round((*bio)->cart[i + 1][j].x);
		(*bio)->y2 = round((*bio)->cart[i + 1][j].y);
	}
	(*bio)->rise = ((*bio)->y2) - ((*bio)->y1);
	(*bio)->run = ((*bio)->x2) - ((*bio)->x1);
	//printf("pixel1: x1[%i]y1[%i]\n", (*bio)->x1, (*bio)->y1);
	//printf("pixel2: x2[%i]y2[%i]\n\n", (*bio)->x2, (*bio)->y2);
}
void	draw_right(t_fdf size, t_bio *bio, t_values **values)
{
	int i;
	int j;

	i = 0;
	bio->k = 1;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width && (i + 1) <= size.height)
		{
			ft_values(&bio, i, j);
			if(bio->run == 0)
				slope_flat(&bio);
			else
			{
				bio->slope = bio->rise/bio->run;
				(*values)->adjust = bio->slope >=0 ? 1 : -1;
				if(bio->slope <= 1 && bio->slope >= -1)
					slope_slow(&bio, *values);
				else
					slope_fast(&bio, *values);
			}
			j++;
		}
		i++;
	}
}
void	draw_down(t_fdf size, t_bio *bio, t_values **values)
{
	int i;
	int j;

	i = 0;
	bio->k = 0;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width && (i + 1) < size.height)
		{
			ft_values(&bio, i, j);
			if(bio->run == 0)
				slope_flat(&bio);
			else
			{
				bio->slope = bio->rise/bio->run;
				(*values)->adjust = bio->slope >=0 ? 1 : -1;
				if (bio->slope <= 1 && bio->slope >= -1)
					slope_slow(&bio, *values);
				else
					slope_fast(&bio, *values);
			}
			j++;
		}
		i++;
	}
}
void	draw_pieces(t_bio *bio, t_fdf size)
{
	t_values	*values;

	values = (t_values *)malloc(sizeof(t_values));
	values->threshold = 0.5;
	values->offset = 0;
	//rotation();
	translate(&bio, size);
	draw_right(size, bio, &values);
	draw_down(size, bio, &values);
	//mlx_key_hook(bio->window, my_key_function, mlx);
	mlx_loop(bio->mlx);
}