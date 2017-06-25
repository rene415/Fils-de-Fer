/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:47:23 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/25 14:47:52 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		file_check(t_fdf *size, int argc, char **argv)
{
	int i;

	i = 1;
	(argc >= 2 && argc <= 6) ? 0 : ft_error_msg("Error: Wrong # of arguments");
	printf("read argc reached\n");
	size->win_x = 0;
	size->win_y = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-w") && (i + 1) < argc)
		{
			size->win_x = ft_atoi(argv[i + 1]);
			printf("-w reached[%i]\n", size->win_x);
		}
		else if (!ft_strcmp(argv[i], "-h") && (i + 1) < argc)
		{
			size->win_x = ft_atoi(argv[i + 1]);
			printf("-h reached[%i]\n", size->win_y);
		}
		else if(!ft_strcmp(argv[i], "--help\n"))
		{
			printf("No Help");
			ft_error_msg("usage: ./fdf FILE [-w width] [-h height]");
		}
		i++;
	}
	size->win_x = (size->win_x < 600 || size->win_x > 1400 ? 800 : size->win_x);
	size->win_y = (size->win_y < 600 || size->win_y > 1000 ? 800 : size->win_y);
}