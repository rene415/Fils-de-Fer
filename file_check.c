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

void		ft_line_check(char *s)
{
	int		i;

	i = 0;
	if (!*s)
		ft_error_msg("Error: Invalid File");
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]) == 1)
			ft_error_msg("Error: Invalid File");
		if ((s[i] == '-' && (!(ft_isdigit(s[i +1])))) || s[i] == '\t')
			ft_error_msg("Error: Invalid File");
		i++;
	}
}
void		ft_valid_file(int fd, int w, t_fdf *size)
{
	int		w1;

	if (get_next_line(fd, &(size->line)))
	{
		ft_line_check(size->line);
		if((size->coor = ft_strsplit(size->line, ' ')) == NULL || !*size->coor)
			ft_error_msg("Error: Wron Content");
		if(!(w = ft_size_x(size->coor)))
			ft_error_msg("Error: Invalid File");
		free(size->coor);
		free(size->line);
	}
	else
		ft_error_msg("File Empty");
	while (get_next_line(fd, &(size->line)))
	{
		ft_line_check(size->line);
		if((size->coor = ft_strsplit(size->line, ' ')) == NULL || !*size->coor)
			ft_error_msg("Error: Wron Content");
		w1 = ft_size_x(size->coor);
		if (w != w1) 
			ft_error_msg("Error: Invalid File");
		free(size->coor);
		free(size->line);
	}
}

void		file_check(t_fdf *size, int argc, char **argv)
{
	int 	i;
	int		w;
	int 	fd;

	i = 1;
	(argc >= 2 && argc <= 6) ? 0 : ft_error_msg("Error: Wrong # of arguments");
	if ((size->str = ft_strstr(argv[1], ".fdf")) == 0)
		ft_error_msg("Error: Wrong File");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error_msg("Error: Unable To Open File");
	ft_valid_file(fd, w, size);
	size->win_x = 0;
	size->win_y = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-w") && (i + 1) < argc)
			size->win_x = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp(argv[i], "-h") && (i + 1) < argc)
			size->win_y = ft_atoi(argv[i + 1]);
		else if(!ft_strcmp(argv[i], "--help\n"))
			ft_error_msg("usage: ./fdf FILE [-w width] [-h height]");
		i++;
	}
	size->win_x = (size->win_x < 300 || size->win_x > 900 ? 700 : size->win_x);
	size->win_y = (size->win_y < 300 || size->win_y > 900 ? 700 : size->win_y);
}
