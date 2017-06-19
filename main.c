/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:29:29 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/13 12:21:26 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_function(int keycode, void *mlx)
{
	printf("Key event  %d\n", keycode);
	//mlx_pixel_put(mlx, 300, 300 0xFF00FF);
	return (0);
}


int	main(int argc, char **argv)
{
	void		*mlx;
	void		*window;
	t_points	*points;
	int 		y;
	int		x;
	int		h;
	int		w;
	int		fd;
	char 		*line;
	char		**file;
	int		i;

//	h = 7;
//	w = 8;
	i = 0;
	if (argc != 2)
		return (0);
	//if (!(points = (t_points*)malloc(sizeof(t_points) * (h+1))))
	//		return (0);
	if((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
	if (get_next_line(fd, &line))
	{
		file = ft_strsplit(line, ' ');
		printf("line is: %s\n", line);
		while (file[1][i] != '\0')
		{
			printf("file is:  %c\n", *file[i]);
			i++;
		}
	}
	close(fd);
	//points[h]= NULL;
	///if (!(t_point*)malloc(sizeof(t_points) * (w + 1)))
	//	return (0);
	/*
	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "mlx 42");
	//sleep(2);
	y = 200;
	while (y < 400)
	{
		x = 0;
		while(x < 0)
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
	*/
	return (0);
}
