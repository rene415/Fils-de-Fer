/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:40 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/03 01:30:08 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"
# include "libft.h"

# define BUFF_SIZE		100
# define TRUE			1
# define FALSE			0

int				get_next_line(const int	fd, char **line);
char			*buff_read(char *buff_store, int fd);
int				ft_len(char *buff_store, char c);
int				store_to_line(char **buff_store, char **line);
#endif
