/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:29:29 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/23 18:30:24 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_function(int keycode, void *mlx)
{
	printf("Key event  %d\n", keycode);
//	mlx_pixel_put(mlx, 300, 300 0xFF00FF);
	return (0);
}

int	main(int argc, char **argv)
{
	//void		*mlx;
	//void		*window;
	t_fdf		*size;

	size = (t_fdf *)malloc(sizeof(t_fdf));
	size->zmax = 0;
	size->zmin = 0;
	if (argc != 2)
		return (0);
	save_file(argv, size);
	//make_env(*size);
/*	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "42 pixels");
	//sleep(2);
	y = 200;
	while (y < 400)
	{
		x = 0;
		while(x < 400)
		{
			mlx_pixel_put(mlx, window, (x), (y - 200), 0xF0FF00);
			mlx_pixel_put(mlx, window, x, y, 0xF0000FF);
			//usleep(50);
			x++;
		}
		y++;
	}
	mlx_key_hook(window, my_key_function, mlx);
	mlx_loop(mlx);
	//sleep(10);
*/
	return (0);
}
