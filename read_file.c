/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 01:51:46 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/03 02:03:16 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		read_file(void)
{
	int 	fd;
	int		*file;
	t_fdf	pieces;

	pieces = (t_fdf)malloc(sizeof(t_fdf))

	fd = open(argv[1], O_RDONLY);
	if (get_next_line(fd, &file) = 1)


	
}
