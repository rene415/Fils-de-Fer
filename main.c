/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:29:29 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/23 19:59:32 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				my_key_function(int keycode, void *mlx)
{
	ft_putstr("Key event: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
	return (0);
}

int				main(int argc, char **argv)
{
	t_bio		*bio;
	t_fdf		*size;

	if (!(size = (t_fdf *)malloc(sizeof(t_fdf))))
		ft_error_msg("Malloc Error");
	size->zmax = 0;
	size->zmin = 0;
	file_check(size, argc, argv);
	save_file(argv, size);
	bio = make_env(*size);
	draw_pieces(bio, *size);
	mlx_key_hook(bio->window, my_key_function, 0);
	mlx_loop(bio->mlx);
	return (0);
}
