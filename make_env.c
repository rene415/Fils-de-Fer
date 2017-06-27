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
	(*bio)->midy = size.height/2;
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
			cart[i][j].z = size.map[i][j] * 3.0;
			j++;
		}
		i++;
	}
	cart[i] = NULL;
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
	bio->gap = size.width > size.height ? size.win_x/(size.width) : size.win_y/(size.height);
	bio->big = size.width > size.height ? size.width : size.height;
	bio->rise = 0;
	bio->run = 0;
	bio->slope = 0;
	bio->max = 800 + (bio->gap) * (bio->big);
	bio->smax = (bio->max) - 300;
	bio->cart = ft_make_cart(&bio, size);
	bio->mlx = mlx_init();
	bio->window = mlx_new_window(bio->mlx, bio->max, bio->smax, "Fils De Fer");
	return (bio);
}
