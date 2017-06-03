/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:53 by rramirez          #+#    #+#             */
/*   Updated: 2017/05/26 14:28:14 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(char *buff_store, char c)
{
	int		len;

	len = 0;
	while (buff_store[len] != '\0' && buff_store[len] != c)
		len++;
	return (len + 1);
}

int		store_to_line(char **buff_store, char **line)
{
	char	*tmpr;
	int		len;

	tmpr = NULL;
	if (ft_strlen(*buff_store))
	{
		len = ft_len(*buff_store, '\n');
		if (ft_strchr(*buff_store, '\n'))
		{
			*line = ft_strsub(*buff_store, 0, (len - 1));
			tmpr = ft_strdup(*buff_store + len);
			free(*buff_store);
			*buff_store = tmpr;
			return (1);
		}
		*line = ft_strdup(*buff_store);
		free(*buff_store);
		*buff_store = NULL;
		return (1);
	}
	return (0);
}

char	*buff_read(char *buff_store, int fd)
{
	size_t			ret;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];

	ret = 0;
	tmp = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!buff_store)
			buff_store = ft_strnew(1);
		tmp = ft_strjoin(buff_store, buff);
		free(buff_store);
		buff_store = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (buff_store);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff_store;
	char			*tmpr;

	tmpr = NULL;
	if (fd == -1 || BUFF_SIZE <= 0 || !line || read(fd, buff_store, 0) < 0)
		return (-1);
	buff_store = buff_read(buff_store, fd);
	if (buff_store == NULL)
		return (0);
	if (store_to_line(&buff_store, line))
		return (1);
	return (0);
}
