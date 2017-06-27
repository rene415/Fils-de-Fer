/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:24:37 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/25 18:28:01 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		x_rot(t_bio **bio,t_fdf size)
{
	float	y;
	float	z;
	int		i;
	int 	j;

	i = 0;
	while(i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			y = (*bio)->cart[i][j].y;
			z = (*bio)->cart[i][j].z;
			(*bio)->cart[i][j].y = (y * cos(0.6982) - z * sin(0.6982));
			(*bio)->cart[i][j].z = (y * sin(0.6982) + z * cos(0.6982));
			j++;
		}
		i++;
	}
}
void		y_rot(t_bio **bio,t_fdf size)
{
	float	x;
	float	z;
	int 	i;
	int 	j;

	i = 0;
	while(i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			x = (*bio)->cart[i][j].x;
			z = (*bio)->cart[i][j].z;
			(*bio)->cart[i][j].x = (x * cos(0.0524) + z * sin(0.0524));
			(*bio)->cart[i][j].z = -(x * sin(0.0524)) + z * cos(0.0524);
			j++;
		}
		i++;
	}
}
void		z_rot(t_bio **bio, t_fdf size)
{
	float	x;
	float	y;
	int 	i;
	int 	j;

	i = 0;
	while(i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			x = (*bio)->cart[i][j].x;
			y = (*bio)->cart[i][j].y;
			(*bio)->cart[i][j].x = (x * cos(0.7854) - y * sin(0.7854));
			(*bio)->cart[i][j].y = (x * sin(0.7854) + y * cos(0.7854));
			j++;
		}
		i++;
	}	
}

void	rotation(t_bio *bio,t_fdf size)
{
	z_rot(&bio, size);
	//y_rot(&bio, size);
	x_rot(&bio, size);
}
