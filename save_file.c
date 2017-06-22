/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:28:34 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/21 16:40:17 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		save_file(char **argv)
{
	int 	i;
	int 	fd;
	char 	*line;
	char	**file;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
   	while(get_next_line(fd, &line))
	{
		i = 0;
		printf("line is: %s\n", line);
		file = ft_strsplit(line, ' ' );
		while (file[i] != '\0')
		{
			printf("%s", file[i]);
			i++;
		}
		printf("\n");
	}
	close (fd);
}
