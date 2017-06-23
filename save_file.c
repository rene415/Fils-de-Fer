/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:28:34 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/22 20:38:46 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coordinates(int fd, char **argv, t_fdf size)
{
	char 	**coord;
	char 	*line;
	int		i;
	int		x;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
	size.map = (int **)malloc(sizeof(int *) * (size.height));
	while (get_next_line(fd, &line))
	{
		i = 0;
		size.map[x] = (int *)malloc(sizeof(int) * (size.width));
		coord = ft_strsplit(line, ' ');
		while (i < size.width)
		{
			size.map[x][i] = ft_atoi(&coord[i][0]);
			printf("%d", size.map[x][i]);
			i++;
		}
		free(coord);
		free(line);
		printf("\n");
		x++;
	}
}

int		ft_width(char **file)
{
	int		i;
	while(file[i])
		i++;
	return (i);
}

void		save_file(char **argv, t_fdf * size)
{
	int 	fd;
	char 	*line;
	char	**file;
	int 	y;

	y = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
   	if (get_next_line(fd, &line))
	{
		y++;
		file = ft_strsplit(line, ' ' );
		free(line);
	}
	size->width = ft_width(file);
	//printf("width is %d\n", size->width);
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	size->height = y;
//	printf("height is: %d\n", size->height);
	close(fd);
	coordinates(fd, argv, *size);
	close (fd);
}
