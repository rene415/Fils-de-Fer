/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 08:54:54 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/24 08:56:59 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_bio **bio, t_fdf size)
{
	int i;
	int	j;
	float x;
	float y;

	i =0;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			x = (*bio)->cart[i][j].x;
			y = (*bio)->cart[i][j].y;
			(*bio)->cart[i][j].x = (x + ((*bio)->max/2));
			(*bio)->cart[i][j].y = (y + ((*bio)->smax/2));
			//printf("old x[%f][%f] -> [%f][%f]\n", x , y, (*bio)->cart[i][j].x, (*bio)->cart[i][j].y);
			j++;
		}
		//printf("\n\n");
		i++;
	}	
	printf("translation = [x = %f] [y = %f]\n", ((*bio)->max / 2), ((*bio)->smax / 2));
}
