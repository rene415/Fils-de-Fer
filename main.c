/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:29:29 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/03 01:09:59 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_function(int keycode, void *mlx)
{
	printf("Key event  %d\n", keycode);
	//mlx_pixel_put(mlx, 300, 300 0xFF00FF);
	return (0);
}


int main(void)
{
	void		*mlx;
	void		*window;
	t_points	*points;
	int 		y;
	int			x;

	//h = 7;
	//w = 8;
//	if (!(points = (t_points**)malloc(sizeof(t_points*) * (h+1))))
//			return (0);
	//points[h]= NULL;
//	if (!(t_point*)malloc(sizeof(t_points) * (w + 1)))
//		return (0);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "mlx 42");
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
//	ft_image_read(void);
	mlx_key_hook(window, my_key_function, mlx);
	mlx_loop(mlx);
	//sleep(10);
	return (0);
}
