/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 08:54:54 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/26 19:43:18 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			translate(t_bio **bio, t_fdf size)
{
	int			i;
	int			j;
	float		x;
	float		y;

	i = 0;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			x = (*bio)->cart[i][j].x;
			y = (*bio)->cart[i][j].y;
			(*bio)->cart[i][j].x = (x + ((*bio)->max / 2));
			(*bio)->cart[i][j].y = (y + ((*bio)->smax / 2));
			j++;
		}
		i++;
	}
}
