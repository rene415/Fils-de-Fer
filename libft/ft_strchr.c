/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:55:02 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 19:43:09 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			c_tmp;
	unsigned char	*s;

	c_tmp = (char)c;
	s = (unsigned char*)str;
	while (*s)
	{
		if (*s == c_tmp)
			return ((char *)s);
		s++;
	}
	if (c_tmp == '\0' && *s == '\0')
		return ((char*)s);
	return (0);
}
