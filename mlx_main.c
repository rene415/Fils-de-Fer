/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:29:29 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/01 22:07:09 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
	void	*mlx;
	void	*window;
	int		x;
	int 	y;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 100;
	while (y < 200)
	{
		x = 10;
		while(x < 200)
		{
			mlx_pixel_put(mlx, window, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
