/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:28:34 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/23 18:36:23 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	value_z(t_fdf **size, int x)
{
	int 	i;
	
	i = 0;
	while (i < (*size)->width)
	{
		(*size)->zmax = (*size)->map[x][i] > (*size)->zmax ? (*size)->map[x][i] : (*size)->zmax;
		(*size)->zmin = (*size)->map[x][i] < (*size)->zmin ? (*size)->map[x][i] : (*size)->zmin;
		i++;
	}
}

void	coordinates(int fd, char **argv, t_fdf **size)
{
	char 	**coord;
	char 	*line;
	int	i;
	int	x;

	x = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
	if (!((*size)->map = (int **)malloc(sizeof(int *) * ((*size)->height + 1))))
			exit(0);
	(*size)->map[(*size)->height] = NULL;
	while (get_next_line(fd, &line))
	{
		i = 0;
		(*size)->map[x] = (int *)malloc(sizeof(int) * ((*size)->width + 1));
		coord = ft_strsplit(line, ' ');
		while (i < (*size)->width)
		{
			(*size)->map[x][i] = ft_atoi(&coord[i][0]);
			//printf("[%3d]", (*size)->map[x][i]);
			i++;
		}
		free(coord);
		free(line);
		//printf("\n");
		value_z(&(*size), x);
		//printf("zmax is: %i\n", (*size)->zmax);
		//printf("zmin is: %i\n\n", (*size)->zmin);
		x++;
	}
}
void		save_file(char **argv, t_fdf *size)
{
	int 	fd;
	char 	*line;
	char	**file;
	int 	y;
	int 	i;

	i = 0;
	y = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
   	while (get_next_line(fd, &line))
	{
		y++;
		file = ft_strsplit(line, ' ');
		free(line);
	}
	while (file[i])
		i++;
	size->width = i;
	free(file);
	size->height = y;
	//printf("width is: %d\n", size->width);
	//printf("height is: %d\n", size->height);
	close(fd);
	coordinates(fd, argv, &size);
	close (fd);
}
