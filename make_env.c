/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/23 10:42:18 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bio	make_env(t_fdf size)
{
	t_bio  *bio;
	
	if (!(bio = (t_bio *)malloc(sizeof(t_bio))))
			exit (0);
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
	bio->smax = (bio->max) - 300;
	//ft_makewindow()
}
