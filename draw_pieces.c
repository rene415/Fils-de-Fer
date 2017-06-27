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

void	ft_values(t_bio **bio, int i, int j, t_fdf size)
{
	(*bio)->x1 = round((*bio)->cart[i][j].x);
	(*bio)->y1 = round((*bio)->cart[i][j].y);
	(*bio)->cur_z = (*bio)->cart[i][j].z;
	if((*bio)->right == 1 && (j + 1) < size.width)
	{
			(*bio)->x2 = round((*bio)->cart[i][j + 1].x);
			(*bio)->y2 = round((*bio)->cart[i][j + 1].y);
			(*bio)->next_z = (*bio)->cart[i][j + 1].z;
	}
	else if ((*bio)->right == 0 && (i + 1) < size.height)
	{
		(*bio)->x2 = round((*bio)->cart[i + 1][j].x);
		(*bio)->y2 = round((*bio)->cart[i + 1][j].y);
		(*bio)->next_z = (*bio)->cart[i + 1][j].z;
	}
	(*bio)->rise = ((*bio)->y2) - ((*bio)->y1);
	(*bio)->run = ((*bio)->x2) - ((*bio)->x1);
}
void	draw_right(t_fdf size, t_bio *bio, t_values **values)
{
	int i;
	int j;

	i = 0;
	bio->right = 1;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			ft_values(&bio, i, j, size);
			if(bio->run == 0)
				slope_flat(bio);
			else
			{
				bio->slope = bio->rise/bio->run;
				(*values)->adjust = bio->slope >=0 ? 1 : -1;
				(*values)->threshold = 0.5;
				(*values)->offset = 0;
				if (bio->slope <= 1 && bio->slope >= -1)
					slope_slow(bio, *values);
				else
					slope_fast(bio, *values);
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
	bio->right = 0;
	printf("height = %d\n", size.height);
	printf("width = %d\n", size.width);
	while (i < size.height)
	{
		j = 0;
		while (j < size.width && (i + 1) < size.height)
		{
			ft_values(&bio, i, j, size);
			if(bio->run == 0)
			{
				slope_flat(bio);
			}
			else
			{
				bio->slope = bio->rise/bio->run;
				(*values)->adjust = bio->slope >= 0 ? 1 : -1;
				(*values)->threshold = 0.5;
				(*values)->offset = 0;
				if (bio->slope <= 1 && bio->slope >= -1)
					slope_slow(bio, *values);
				else
					slope_fast(bio, *values);
			}
			j++;
		}
		i++;
	}
}
void	draw_pieces(t_bio *bio, t_fdf size)
{
	t_values	*values;

	if(!(values = (t_values *)malloc(sizeof(t_values))))
		ft_error_msg("Error: Malloc Failed\n");
	rotation(bio,size);
	translate(&bio, size);
	draw_right(size, bio, &values);
	draw_down(size, bio, &values);
}