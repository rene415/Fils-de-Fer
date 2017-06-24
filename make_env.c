/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/23 18:33:31 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_cart(t_bio **bio, t_fdf size)
{
	//(*bio)->mlx = mlx_init();
	//(*bio)->window = mlx_new_window((*bio)->mlx, (*bio)->max, (*bio)->smax, "Fils De Fer");
}

void	make_env(t_fdf size)
{
	t_bio  *bio;
	
	if (!(bio = (t_bio *)malloc(sizeof(t_bio))))
			exit (0);
	bio->x1 = 0;
	bio->x2 = 0;
	bio->y1 = 0;
	bio->y2 = 0;
	bio->gap = size.width > size.height ? 600/(size.width) : 600/(size.height);
	bio->big = size.width > size.height ? size.width : size.height;
	bio->rise = 0;
	bio->run = 0;
	bio->slope = 0;
	bio->max = 800 + (bio->gap) * (bio->big);
	printf("max is = %i\n", bio->max);
	bio->smax = (bio->max) - 300;
	printf("smax is = %i\n", bio->smax);
	//ft_make_cart(&bio, size);
}
