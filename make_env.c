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

t_cartp		**ft_make_cart(t_bio **bio, t_fdf size)
{
	int 	i;
	int 	j;
	t_cartp	**cart;

	(*bio)->midx = size.width/2;
	//printf("midx is: %i\n", (*bio)->midx);
	(*bio)->midy = size.height/2;
	//printf("midy is: %i\n", (*bio)->midy);
	cart = (t_cartp **)malloc(sizeof(t_cartp *) * (size.height + 1));
	i = 0;
	while (i < size.height)
	{
		j = 0;
		cart[i] = (t_cartp *)malloc(sizeof(t_cartp) * (size.width + 1));
		while (j < size.width)
		{
			cart[i][j].x = (j - (*bio)->midx) * (*bio)->gap;
			cart[i][j].y = (i - (*bio)->midy) * (*bio)->gap;
			//cart[i][j].z = size.map[i][j] * 8;
			cart[i][j].z = size.map[i][j];
			j++;
		}
		i++;
	}
	cart[i] = NULL;
	// printf("x/width = %d, y/height = %d\n", size.width, size.height);
	// printf("midx = %d, midy = %d\n", (*bio)->midx, (*bio)->midy);
	// printf("(0,0) = (%f, %f)\n", cart[0][0].y, cart[0][0].x);
	// printf("(0,1) = (%f, %f)\n", cart[0][1].y, cart[0][1].x);
	// printf("(1,0) = (%f, %f)\n", cart[1][0].y, cart[1][0].x);
	// printf("(%d,%d) = (%f, %f)\n", (*bio)->midy, (*bio)->midx, cart[(*bio)->midy][(*bio)->midx].y, cart[(*bio)->midy][(*bio)->midx].x);
	// printf("(9,14) = (%f, %f)\n", cart[9][14].y, cart[9][14].x);
	return (cart);
}

t_bio	*make_env(t_fdf size)
{
	t_bio  *bio;
	
	if (!(bio = (t_bio *)malloc(sizeof(t_bio))))
			ft_error_msg("Error: Malloc Failed\n");
	bio->right = 0;
	bio->x1 = 0;
	bio->x2 = 0;
	bio->y1 = 0;
	bio->y2 = 0;
	bio->gap = size.width > size.height ? 700/(size.width) : 700/(size.height);
	bio->big = size.width > size.height ? size.width : size.height;
	bio->rise = 0;
	bio->run = 0;
	bio->slope = 0;
	bio->max = 800 + (bio->gap) * (bio->big);
	printf("gap is: %d\n", bio->gap);	
	//printf("zmax: %i\n", size.zmax);
	//printf("zmin: %i\n", size.zmin);
	//printf("max is = %i\n", bio->max);
	bio->smax = (bio->max) - 300;
	//printf("smax is = %i\n", bio->smax);
	bio->cart = ft_make_cart(&bio, size);
	bio->mlx = mlx_init();
	bio->window = mlx_new_window(bio->mlx, bio->max, bio->smax, "Fils De Fer");
	return (bio);
}
